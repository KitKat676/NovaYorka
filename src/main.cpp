#include <chrono>
#include <fcntl.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>

using json = nlohmann::json;

#include "calcwit.hpp"
#include "circom.hpp"

#define handle_error(msg)                                                      \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

Circom_Circuit *loadCircuit(std::string const &datFileName) {
  Circom_Circuit *circuit = new Circom_Circuit;

  int fd;
  struct stat sb;

  // printf("Got to this point\n");

  fd = open(datFileName.c_str(), O_RDONLY);
  if (fd == -1) {
    std::cout << ".dat file not found: " << datFileName << "\n";
    throw std::system_error(errno, std::generic_category(), "open");
  }

  if (fstat(fd, &sb) == -1) { /* To obtain file size */
    throw std::system_error(errno, std::generic_category(), "fstat");
  }

  u8 *bdata = (u8 *)mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  close(fd);

  circuit->InputHashMap = new HashSignalInfo[get_size_of_input_hashmap()];
  uint dsize = get_size_of_input_hashmap() * sizeof(HashSignalInfo);
  memcpy((void *)(circuit->InputHashMap), (void *)bdata, dsize);

  circuit->witness2SignalList = new u64[get_size_of_witness()];
  uint inisize = dsize;
  dsize = get_size_of_witness() * sizeof(u64);
  memcpy((void *)(circuit->witness2SignalList), (void *)(bdata + inisize),
         dsize);

  circuit->circuitConstants = new FrElement[get_size_of_constants()];
  if (get_size_of_constants() > 0) {
    inisize += dsize;
    dsize = get_size_of_constants() * sizeof(FrElement);
    memcpy((void *)(circuit->circuitConstants), (void *)(bdata + inisize),
           dsize);
  }

  std::map<u32, IOFieldDefPair> templateInsId2IOSignalInfo1;
  IOFieldDefPair *busInsId2FieldInfo1;
  if (get_size_of_io_map() > 0) {
    u32 index[get_size_of_io_map()];
    inisize += dsize;
    dsize = get_size_of_io_map() * sizeof(u32);
    memcpy((void *)index, (void *)(bdata + inisize), dsize);
    inisize += dsize;
    assert(inisize % sizeof(u32) == 0);
    assert(sb.st_size % sizeof(u32) == 0);
    u32 dataiomap[(sb.st_size - inisize) / sizeof(u32)];
    memcpy((void *)dataiomap, (void *)(bdata + inisize), sb.st_size - inisize);
    u32 *pu32 = dataiomap;
    for (int i = 0; i < get_size_of_io_map(); i++) {
      u32 n = *pu32;
      IOFieldDefPair p;
      p.len = n;
      IOFieldDef defs[n];
      pu32 += 1;
      for (u32 j = 0; j < n; j++) {
        defs[j].offset = *pu32;
        u32 len = *(pu32 + 1);
        defs[j].len = len;
        defs[j].lengths = new u32[len];
        memcpy((void *)defs[j].lengths, (void *)(pu32 + 2), len * sizeof(u32));
        pu32 += len + 2;
        defs[j].size = *pu32;
        defs[j].busId = *(pu32 + 1);
        pu32 += 2;
      }
      p.defs = (IOFieldDef *)calloc(p.len, sizeof(IOFieldDef));
      for (u32 j = 0; j < p.len; j++) {
        p.defs[j] = defs[j];
      }
      templateInsId2IOSignalInfo1[index[i]] = p;
    }
    busInsId2FieldInfo1 = (IOFieldDefPair *)calloc(get_size_of_bus_field_map(),
                                                   sizeof(IOFieldDefPair));
    for (int i = 0; i < get_size_of_bus_field_map(); i++) {
      u32 n = *pu32;
      IOFieldDefPair p;
      p.len = n;
      IOFieldDef defs[n];
      pu32 += 1;
      for (u32 j = 0; j < n; j++) {
        defs[j].offset = *pu32;
        u32 len = *(pu32 + 1);
        defs[j].len = len;
        defs[j].lengths = new u32[len];
        memcpy((void *)defs[j].lengths, (void *)(pu32 + 2), len * sizeof(u32));
        pu32 += len + 2;
        defs[j].size = *pu32;
        defs[j].busId = *(pu32 + 1);
        pu32 += 2;
      }
      p.defs = (IOFieldDef *)calloc(10, sizeof(IOFieldDef));
      for (u32 j = 0; j < p.len; j++) {
        p.defs[j] = defs[j];
      }
      busInsId2FieldInfo1[i] = p;
    }
  }
  circuit->templateInsId2IOSignalInfo = move(templateInsId2IOSignalInfo1);
  circuit->busInsId2FieldInfo = busInsId2FieldInfo1;

  munmap(bdata, sb.st_size);

  return circuit;
}

bool check_valid_number(std::string &s, uint base) {
  bool is_valid = true;
  if (base == 16) {
    for (uint i = 0; i < s.size(); i++) {
      is_valid &=
          (('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f') ||
           ('A' <= s[i] && s[i] <= 'F'));
    }
  } else {
    for (uint i = 0; i < s.size(); i++) {
      is_valid &= ('0' <= s[i] && s[i] < char(int('0') + base));
    }
  }
  return is_valid;
}

void json2FrElements(json val, std::vector<FrElement> &vval) {
  if (!val.is_array()) {
    FrElement v;
    std::string s_aux, s;
    uint base;
    if (val.is_string()) {
      s_aux = val.get<std::string>();
      std::string possible_prefix = s_aux.substr(0, 2);
      if (possible_prefix == "0b" || possible_prefix == "0B") {
        s = s_aux.substr(2, s_aux.size() - 2);
        base = 2;
      } else if (possible_prefix == "0o" || possible_prefix == "0O") {
        s = s_aux.substr(2, s_aux.size() - 2);
        base = 8;
      } else if (possible_prefix == "0x" || possible_prefix == "0X") {
        s = s_aux.substr(2, s_aux.size() - 2);
        base = 16;
      } else {
        s = s_aux;
        base = 10;
      }
      if (!check_valid_number(s, base)) {
        std::ostringstream errStrStream;
        errStrStream << "Invalid number in JSON input: " << s_aux << "\n";
        throw std::runtime_error(errStrStream.str());
      }
    } else if (val.is_number()) {
      double vd = val.get<double>();
      std::stringstream stream;
      stream << std::fixed << std::setprecision(0) << vd;
      s = stream.str();
      base = 10;
    } else {
      std::ostringstream errStrStream;
      errStrStream << "Invalid JSON type\n";
      throw std::runtime_error(errStrStream.str());
    }
    Fr_str2element(&v, s.c_str(), base);
    vval.push_back(v);
  } else {
    for (uint i = 0; i < val.size(); i++) {
      json2FrElements(val[i], vval);
    }
  }
}

json::value_t check_type(std::string prefix, json in) {
  if (not in.is_array()) {
    if (in.is_number_integer() || in.is_number_unsigned() || in.is_string())
      return json::value_t::number_integer;
    else
      return in.type();
  } else {
    if (in.size() == 0)
      return json::value_t::null;
    json::value_t t = check_type(prefix, in[0]);
    for (uint i = 1; i < in.size(); i++) {
      if (t != check_type(prefix, in[i])) {
        fprintf(stderr, "Types are not the same in the key %s\n",
                prefix.c_str());
        assert(false);
      }
    }
    return t;
  }
}

void qualify_input(std::string prefix, json &in, json &in1);

void qualify_input_list(std::string prefix, json &in, json &in1) {
  if (in.is_array()) {
    for (uint i = 0; i < in.size(); i++) {
      std::string new_prefix = prefix + "[" + std::to_string(i) + "]";
      qualify_input_list(new_prefix, in[i], in1);
    }
  } else {
    qualify_input(prefix, in, in1);
  }
}

void qualify_input(std::string prefix, json &in, json &in1) {
  if (in.is_array()) {
    if (in.size() > 0) {
      json::value_t t = check_type(prefix, in);
      if (t == json::value_t::object) {
        qualify_input_list(prefix, in, in1);
      } else {
        in1[prefix] = in;
      }
    } else {
      in1[prefix] = in;
    }
  } else if (in.is_object()) {
    for (json::iterator it = in.begin(); it != in.end(); ++it) {
      std::string new_prefix =
          prefix.length() == 0 ? it.key() : prefix + "." + it.key();
      qualify_input(new_prefix, it.value(), in1);
    }
  } else {
    in1[prefix] = in;
  }
}

void loadJson(Circom_CalcWit *ctx, std::string json_str) {
  // std::ifstream inStream(filename);
  std::istringstream inStream(json_str);
  json jin;
  inStream >> jin;
  json j;

  // std::cout << jin << std::endl;
  std::string prefix = "";
  qualify_input(prefix, jin, j);
  // std::cout << j << std::endl;

  u64 nItems = j.size();
  // printf("Items : %llu\n",nItems);
  if (nItems == 0) {
    ctx->tryRunCircuit();
  }
  for (json::iterator it = j.begin(); it != j.end(); ++it) {
    // std::cout << it.key() << " => " << it.value() << '\n';
    u64 h = fnv1a(it.key());
    std::vector<FrElement> v;
    json2FrElements(it.value(), v);
    uint signalSize = ctx->getInputSignalSize(h);
    if (v.size() < signalSize) {
      std::ostringstream errStrStream;
      errStrStream << "Error loading signal " << it.key()
                   << ": Not enough values\n";
      throw std::runtime_error(errStrStream.str());
    }
    if (v.size() > signalSize) {
      std::ostringstream errStrStream;
      errStrStream << "Error loading signal " << it.key()
                   << ": Too many values\n";
      throw std::runtime_error(errStrStream.str());
    }
    for (uint i = 0; i < v.size(); i++) {
      try {
        // std::cout << it.key() << "," << i << " => " <<
        // Fr_element2str(&(v[i])) << '\n';
        ctx->setInputSignal(h, i, v[i]);
      } catch (std::runtime_error e) {
        std::ostringstream errStrStream;
        errStrStream << "Error setting signal: " << it.key() << "\n"
                     << e.what();
        throw std::runtime_error(errStrStream.str());
      }
    }
  }
}

void writeBinWitness(Circom_CalcWit *ctx, std::string wtnsFileName) {
  FILE *write_ptr;

  // printf("Started writing witness\n");
  write_ptr = fopen(wtnsFileName.c_str(), "wb");

  fwrite("wtns", 4, 1, write_ptr);

  u32 version = 2;
  fwrite(&version, 4, 1, write_ptr);

  u32 nSections = 2;
  fwrite(&nSections, 4, 1, write_ptr);

  // Header
  u32 idSection1 = 1;
  fwrite(&idSection1, 4, 1, write_ptr);

  u32 n8 = Fr_N64 * 8;

  u64 idSection1length = 8 + n8;
  fwrite(&idSection1length, 8, 1, write_ptr);

  fwrite(&n8, 4, 1, write_ptr);

  fwrite(Fr_q.longVal, Fr_N64 * 8, 1, write_ptr);

  uint Nwtns = get_size_of_witness();

  u32 nVars = (u32)Nwtns;
  fwrite(&nVars, 4, 1, write_ptr);

  // Data
  u32 idSection2 = 2;
  fwrite(&idSection2, 4, 1, write_ptr);

  u64 idSection2length = (u64)n8 * (u64)Nwtns;
  fwrite(&idSection2length, 8, 1, write_ptr);

  FrElement v;

  for (int i = 0; i < Nwtns; i++) {
    ctx->getWitness(i, &v);
    Fr_toLongNormal(&v, &v);
    fwrite(v.longVal, Fr_N64 * 8, 1, write_ptr);
  }
  // printf("Finished writing witness\n");
  fclose(write_ptr);
}

/**
 * @brief Helper function to write arbitrary data to a std::vector<unsigned
 * char>. This mimics the behavior of fwrite for an in-memory buffer.
 *
 * @param ptr A pointer to the data to be written.
 * @param size The size of each item to be written (in bytes).
 * @param count The number of items to be written.
 * @param buffer The std::vector<unsigned char> to which the data will be
 * appended.
 */
void write_to_vector(const void *ptr, size_t size, size_t count,
                     std::vector<unsigned char> &buffer) {
  // Cast the void pointer to a const unsigned char pointer to iterate over
  // bytes
  const unsigned char *bytes = static_cast<const unsigned char *>(ptr);
  // Calculate the total number of bytes to append
  size_t total_bytes = size * count;
  // Append the bytes from the source pointer to the end of the vector
  buffer.insert(buffer.end(), bytes, bytes + total_bytes);
}

/**
 * @brief Writes binary witness data to a byte array in memory.
 * This function is a modified version of the original 'writeBinWitness'
 * that outputs to a std::vector<unsigned char> instead of a file.
 *
 * @param ctx A pointer to the Circom_CalcWit context, used to retrieve witness
 * values.
 * @return A std::vector<unsigned char> containing the binary witness data.
 */
std::vector<unsigned char> writeBinWitnessToMemory(Circom_CalcWit *ctx) {
  // Initialize an empty vector that will store the binary data.
  // It will grow dynamically as data is written to it.
  std::vector<unsigned char> buffer;

  // Original: fwrite("wtns", 4, 1, write_ptr);
  write_to_vector("wtns", 4, 1, buffer);

  // Original: u32 version = 2; fwrite(&version, 4, 1, write_ptr);
  u32 version = 2;
  write_to_vector(&version, 4, 1, buffer);

  // Original: u32 nSections = 2; fwrite(&nSections, 4, 1, write_ptr);
  u32 nSections = 2;
  write_to_vector(&nSections, 4, 1, buffer);

  // --- Header Section (ID 1) ---
  // Original: u32 idSection1 = 1; fwrite(&idSection1, 4, 1, write_ptr);
  u32 idSection1 = 1;
  write_to_vector(&idSection1, 4, 1, buffer);

  // Calculate n8: number of bytes per field element limb (Fr_N64 * 8
  // bytes/limb) Assuming Fr_N64 is the number of 64-bit limbs in
  // FrElement.longVal, and each limb is 8 bytes.
  u32 n8 =
      Fr_N64 * 8; // Total bytes for a full FrElement (e.g., 4 * 8 = 32 bytes)

  // Original: u64 idSection1length = 8 + n8; fwrite(&idSection1length, 8, 1,
  // write_ptr);
  u64 idSection1length = 8 + n8;
  write_to_vector(&idSection1length, 8, 1, buffer);

  // Original: fwrite(&n8, 4, 1, write_ptr);
  write_to_vector(&n8, 4, 1, buffer);

  // Original: fwrite(Fr_q.longVal, Fr_N64*8, 1, write_ptr);
  // Ensure Fr_q is properly initialized before this call in your actual
  // application.
  write_to_vector(Fr_q.longVal, Fr_N64 * 8, 1, buffer);

  // Get the total number of witness variables
  uint Nwtns = get_size_of_witness();

  // Original: u32 nVars = (u32)Nwtns; fwrite(&nVars, 4, 1, write_ptr);
  u32 nVars = (u32)Nwtns;
  write_to_vector(&nVars, 4, 1, buffer);

  // --- Data Section (ID 2) ---
  // Original: u32 idSection2 = 2; fwrite(&idSection2, 4, 1, write_ptr);
  u32 idSection2 = 2;
  write_to_vector(&idSection2, 4, 1, buffer);

  // Original: u64 idSection2length = (u64)n8*(u64)Nwtns;
  // fwrite(&idSection2length, 8, 1, write_ptr);
  u64 idSection2length = (u64)n8 * (u64)Nwtns;
  write_to_vector(&idSection2length, 8, 1, buffer);

  FrElement v; // Temporary variable to hold each witness value

  // Loop through all witness variables and write their values
  for (int i = 0; i < Nwtns; i++) {
    ctx->getWitness(i, &v);  // Get the witness value
    Fr_toLongNormal(&v, &v); // Normalize the witness value
    // Original: fwrite(v.longVal, Fr_N64*8, 1, write_ptr);
    write_to_vector(v.longVal, Fr_N64 * 8, 1,
                    buffer); // Write the normalized value (n8 bytes)
  }

  return buffer; // Return the populated byte array
}

/**
 * @brief Writes the contents of a std::vector<unsigned char> to a specified
 * file.
 *
 * @param wtns The std::vector<unsigned char> containing the bytes to write.
 * @param file_name The path and name of the file to write to.
 * @return true if the write operation was successful, false otherwise.
 */
bool writeVectorToFile(const std::vector<unsigned char> &wtns,
                       const std::string &file_name) {
  FILE *write_ptr;
  write_ptr = fopen(file_name.c_str(), "wb"); // Open file in binary write mode

  if (write_ptr == NULL) {
    std::cerr << "Error: Could not open file " << file_name << " for writing."
              << std::endl;
    return false;
  }

  // Write the entire contents of the vector to the file
  size_t bytes_written = fwrite(wtns.data(), 1, wtns.size(), write_ptr);

  fclose(write_ptr); // Close the file

  if (bytes_written != wtns.size()) {
    std::cerr << "Error: Mismatch in bytes written. Expected " << wtns.size()
              << ", but wrote " << bytes_written << " to " << file_name
              << std::endl;
    return false;
  }

  return true; // Successfully wrote all bytes
}

extern "C" {
void free_analyzer_output(char *ptr) { free(ptr); }

//int analyzer_main(char *json_str, char *wtns_file) {
int analyzer_main(char* json_str, char** witness_out_ptr, u64* witness_out_len) {
  // auto t_start = std::chrono::high_resolution_clock::now();

  // Use static circuit to avoid repeated R1CS loading, but create fresh context each time
  static Circom_Circuit *circuit = nullptr;
  
  // Initialize circuit only once (the expensive part)
  if (circuit == nullptr) {
    std::string datfile = "analyzer_cpp/analyzer.dat";
    circuit = loadCircuit(datfile);
  }

  // Create a fresh context for each call to avoid state pollution
  Circom_CalcWit *ctx = new Circom_CalcWit(circuit);

  // printf("About to load Json\n");
  loadJson(ctx, std::string(json_str));
  // printf("Loaded Json\n");
  if (ctx->getRemaingInputsToBeSet() != 0) {
    std::cerr << "Not all inputs have been set. Only "
              << get_main_input_signal_no() - ctx->getRemaingInputsToBeSet()
              << " out of " << get_main_input_signal_no() << std::endl;
    assert(false);
  }

  std::vector<unsigned char> wtns = writeBinWitnessToMemory(ctx);

  // writeBinWitness(ctx,std::string (wtns_file));
  //writeVectorToFile(wtns, std::string(wtns_file));

  int total_buffer_size = wtns.size();

  char* buffer = (char*)malloc(total_buffer_size);

  memcpy(buffer, wtns.data(), total_buffer_size);
  *witness_out_ptr = buffer;
  *witness_out_len = total_buffer_size;

  // Clean up the context after each use, but keep the circuit
  delete ctx;

  return 0;
}
}
