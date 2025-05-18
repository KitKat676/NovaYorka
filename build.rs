use std::process::Command;
use std::env;
use std::fs;

fn main() {
    println!("Starting to compile C++ code");
    let out_dir = env::var("OUT_DIR").unwrap();

    // Step 1: Compile the C++ files into a static library
    cc::Build::new()
        .cpp(true)
        .files([
            "src/analyzer.cpp",
            "src/calcwit.cpp",
            "src/fr.cpp",
            "src/main.cpp",
        ])
        .flag_if_supported("-std=c++17")
        .compile("nativecode");

    // Step 2: Compile the NASM assembly file into an object file
    let asm_output = format!("{}/fr.o", out_dir);
    let status = Command::new("nasm")
        .args(["-f", "elf64", "src/fr.asm", "-o", &asm_output])
        .status()
        .expect("Failed to run nasm");
    assert!(status.success(), "NASM assembly failed");

    // Step 3: Tell Cargo to link the object manually
    println!("cargo:rustc-link-search=native={}", out_dir);
    println!("cargo:rustc-link-lib=static=fr");

    // Optional: Create a static lib from fr.o so it's usable with link-lib
    let _ = Command::new("ar")
        .args(["crus", "libfr.a", "fr.o"])
        .current_dir(&out_dir)
        .status()
        .expect("Failed to create libfr.a");
    println!("Ending compile C++ code");
}
