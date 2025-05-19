#include "calcwit.hpp"
#include "circom.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include "main.cpp"

extern "C"
{

    Circom_Circuit *load_circuit(const char *dat_path)
    {
        return loadCircuit(std::string(dat_path));
    }

    Circom_CalcWit *create_ctx(Circom_Circuit *circuit)
    {
        return new Circom_CalcWit(circuit);
    }

    bool load_json_from_str(Circom_CalcWit *ctx, const char *json_str, char **err_msg_out)
    {
        try
        {
            std::istringstream iss(json_str);
            json jinput;
            iss >> jinput;
            json j;
            qualify_input("", jinput, j);
            if (j.empty())
            {
                ctx->tryRunCircuit();
                return true;
            }

            for (json::iterator it = j.begin(); it != j.end(); ++it)
            {
                u64 h = fnv1a(it.key());
                std::vector<FrElement> v;
                json2FrElements(it.value(), v);
                uint signalSize = ctx->getInputSignalSize(h);
                if (v.size() != signalSize)
                {
                    std::ostringstream oss;
                    oss << "Incorrect number of values for signal " << it.key();
                    std::string err = oss.str();
                    *err_msg_out = strdup(err.c_str());
                    return false;
                }
                for (uint i = 0; i < v.size(); i++)
                {
                    ctx->setInputSignal(h, i, v[i]);
                }
            }

            return true;
        }
        catch (const std::exception &e)
        {
            *err_msg_out = strdup(e.what());
            return false;
        }
    }

    bool write_witness_to_file(Circom_CalcWit *ctx, const char *output_path, char **err_msg_out)
    {
        try
        {
            writeBinWitness(ctx, std::string(output_path));
            return true;
        }
        catch (const std::exception &e)
        {
            *err_msg_out = strdup(e.what());
            return false;
        }
    }

    void destroy_ctx(Circom_CalcWit *ctx)
    {
        delete ctx;
    }

    void destroy_circuit(Circom_Circuit *circuit)
    {
        delete circuit;
    }

    void free_err_msg(char *msg)
    {
        free(msg);
    }
}
