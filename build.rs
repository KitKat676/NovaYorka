use std::process::Command;
use std::env;

fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();

    // Step 1: Compile C++ sources into a static lib
    cc::Build::new()
        .cpp(true)
        .files([
            "src/analyzer.cpp",
            "src/calcwit.cpp",
            "src/fr.cpp",
            "src/main.cpp",
            //"src/ffi_wrappers.cpp",
        ])
        .flag_if_supported("-std=c++11")
        .flag_if_supported("-O3")
        .include("src") // Adjust if your headers are elsewhere
        .compile("nativecode");

    // Step 2: Assemble fr.asm using nasm
    let asm_output = format!("{}/fr_asm.o", out_dir);
    let status = Command::new("nasm")
        .args(["-felf64", "src/fr.asm", "-o", &asm_output])
        .status()
        .expect("Failed to run nasm");
    assert!(status.success(), "NASM assembly failed");

    // Step 3: Create static library from fr_asm.o
    let status = Command::new("ar")
        .args(["crus", "libfrasm.a", "fr_asm.o"])
        .current_dir(&out_dir)
        .status()
        .expect("Failed to create libfrasm.a");
    assert!(status.success());

    // Step 4: Link directories and libraries
    println!("cargo:rustc-link-search=native={}", out_dir);
    println!("cargo:rustc-link-lib=static=frasm");
    println!("cargo:rustc-link-lib=gmp");
}

