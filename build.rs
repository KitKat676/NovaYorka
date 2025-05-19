use std::env;
use std::path::Path;
use std::process::Command;

fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();
    let out_path = Path::new(&out_dir);

    // Step 1: Compile C++ sources into a static lib
    cc::Build::new()
        .cpp(true)
        .files([
            "src/analyzer.cpp",
            "src/calcwit.cpp",
            "src/fr.cpp",
            "src/main.cpp",
        ])
        .flag_if_supported("-std=c++11")
        .flag_if_supported("-O3")
        .include("src")
        .compile("nativecode"); // Produces libnativecode.a in OUT_DIR

    // Step 2: Assemble fr.asm using nasm
    let asm_output = out_path.join("fr_asm.o");
    let status = Command::new("nasm")
        .args([
            "-felf64",
            "src/fr.asm",
            "-o",
            asm_output.to_str().unwrap(),
        ])
        .status()
        .expect("Failed to run nasm");
    assert!(status.success(), "NASM assembly failed");

    // Step 3: Create libfrasm.a from fr_asm.o
    let status = Command::new("ar")
        .args(["crus", "libfrasm.a", "fr_asm.o"])
        .current_dir(&out_path)
        .status()
        .expect("Failed to create libfrasm.a");
    assert!(status.success());

    // Step 4: Tell Rust to link with both static libs and GMP
    println!("cargo:rustc-link-search=native={}", out_dir);
    println!("cargo:rustc-link-lib=static=nativecode");
    println!("cargo:rustc-link-lib=static=frasm");
    println!("cargo:rustc-link-lib=gmp");
}

