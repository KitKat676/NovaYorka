use std::{
    collections::HashMap,
    env::current_dir,
    fs,
    path::{Path, PathBuf},
};
use std::time::Instant;

use crate::circom::reader::{generate_witness_from_bin, load_r1cs};
use circom::circuit::{CircomCircuit, R1CS};
use ff::Field;
use nova_snark::{
    traits::{circuit::TrivialTestCircuit, Group},
    PublicParams, RecursiveSNARK,
};
use num_bigint::BigInt;
use num_traits::Num;
use serde::{Deserialize, Serialize};
use serde_json::Value;

pub mod circom;

pub type F<G> = <G as Group>::Scalar;
pub type EE<G> = nova_snark::provider::ipa_pc::EvaluationEngine<G>;
pub type S<G> = nova_snark::spartan::snark::RelaxedR1CSSNARK<G, EE<G>>;
pub type C1<G> = CircomCircuit<<G as Group>::Scalar>;
pub type C2<G> = TrivialTestCircuit<<G as Group>::Scalar>;

#[derive(Clone)]
pub enum FileLocation {
    PathBuf(PathBuf),
    URL(String),
}

/// Memory usage information in KB
#[derive(Debug)]
struct MemoryInfo {
    rss: u64,     // Resident Set Size (physical memory currently used)
    vms: u64,     // Virtual Memory Size (total virtual memory used)
    peak: u64,    // Peak memory usage
}

/// Read current memory usage from /proc/self/status (Linux-specific)
fn get_memory_usage() -> Option<MemoryInfo> {
    let status = fs::read_to_string("/proc/self/status").ok()?;
    
    let mut rss = 0u64;
    let mut vms = 0u64;
    let mut peak = 0u64;
    
    for line in status.lines() {
        if line.starts_with("VmRSS:") {
            rss = line.split_whitespace()
                .nth(1)?
                .parse()
                .ok()?;
        } else if line.starts_with("VmSize:") {
            vms = line.split_whitespace()
                .nth(1)?
                .parse()
                .ok()?;
        } else if line.starts_with("VmPeak:") {
            peak = line.split_whitespace()
                .nth(1)?
                .parse()
                .ok()?;
        }
    }
    
    Some(MemoryInfo { rss, vms, peak })
}

pub fn create_public_params<G1, G2>(r1cs: R1CS<F<G1>>) -> PublicParams<G1, G2, C1<G1>, C2<G2>>
    where
        G1: Group<Base = <G2 as Group>::Scalar>,
        G2: Group<Base = <G1 as Group>::Scalar>,
{
    let circuit_primary = CircomCircuit {
        r1cs,
        witness: None,
    };
    let circuit_secondary = TrivialTestCircuit::default();

    PublicParams::setup(circuit_primary.clone(), circuit_secondary.clone())
}

#[derive(Serialize, Deserialize)]
struct CircomInput {
    step_in: Vec<String>,

    #[serde(flatten)]
    extra: HashMap<String, Value>,
}

fn compute_witness<G1, G2>(
    current_public_input: Vec<String>,
    private_input: HashMap<String, Value>,
    _witness_generator_file: FileLocation,
    _witness_generator_output: &Path,
) -> Vec<<G1 as Group>::Scalar>
    where
        G1: Group<Base = <G2 as Group>::Scalar>,
        G2: Group<Base = <G1 as Group>::Scalar>,
{
    let decimal_stringified_input: Vec<String> = current_public_input
        .iter()
        .map(|x| BigInt::from_str_radix(x, 16).unwrap().to_str_radix(10))
        .collect();

    let input = CircomInput {
        step_in: decimal_stringified_input.clone(),
        extra: private_input.clone(),
    };

    let input_json = serde_json::to_string(&input).unwrap();

    // Always use the binary witness generator since WASM is not supported
    generate_witness_from_bin::<F<G1>>(
        &input_json,
    )
}

pub fn create_recursive_circuit<G1, G2>(
    witness_generator_file: FileLocation,
    //r1cs: R1CS<F<G1>>,
    private_inputs: Vec<HashMap<String, Value>>,
    start_public_input: Vec<F<G1>>,
    //pp: &PublicParams<G1, G2, C1<G1>, C2<G2>>,
    keyword: &str,
) -> Result<(Vec<<G1 as Group>::Scalar>,RecursiveSNARK<G1, G2, C1<G1>, C2<G2>>,PublicParams<G1, G2, C1<G1>, C2<G2>>), std::io::Error>
    where
        G1: Group<Base = <G2 as Group>::Scalar>,
        G2: Group<Base = <G1 as Group>::Scalar>,
{

    println!("This is the n_input version of Nova Yorka\n");
    //println!("Looking for circuit at: {:?}", circuit_file);
    //let r1cs = load_r1cs::<G1, G2>(&FileLocation::PathBuf(circuit_file));
    //println!("Loaded the R1CS file.");
    let root = current_dir().unwrap();
    let circuit_file = root.join("analyzer.r1cs".to_string());
    println!("Loading R1CS from {}", circuit_file.display());
    let r1cs = load_r1cs::<G1, G2>(&FileLocation::PathBuf(circuit_file));
    println!("Loaded R1CS ");
    println!("Creating public parameters based on R1CS ");
    let start = Instant::now();
    // Only clone R1CS once for public parameter creation
    let pp: PublicParams<G1, G2, _, _> = create_public_params(r1cs.clone());
    let pub_time = start.elapsed();
    //println!("PublicParams creation took {:?}", start.elapsed());

    let witness_generator_output = root.join("circom_witness.wtns");

    let iteration_count = private_inputs.len();

    let start_public_input_hex = start_public_input
        .iter()
        .map(|&x| format!("{:?}", x).strip_prefix("0x").unwrap().to_string())
        .collect::<Vec<String>>();
    let mut current_public_input = start_public_input_hex.clone();

    let witness_0 = compute_witness::<G1, G2>(
        current_public_input.clone(),
        private_inputs[0].clone(),
        witness_generator_file.clone(),
        &witness_generator_output,
    );

    // Create a single circuit instance that will be reused throughout
    let mut reusable_circuit = CircomCircuit {
        r1cs,
        witness: Some(witness_0),
    };
    let circuit_secondary = TrivialTestCircuit::default();
    let z0_secondary = vec![G2::Scalar::ZERO];

    let mut recursive_snark = RecursiveSNARK::<G1, G2, C1<G1>, C2<G2>>::new(
        &pp,
        &reusable_circuit,
        &circuit_secondary,
        start_public_input.clone(),
        z0_secondary.clone(),
    );
    let mut current_public_output = reusable_circuit.get_public_outputs();
    
    // Print initial memory usage before starting iterations
    if let Some(memory_info) = get_memory_usage() {
        println!("Initial memory usage: RSS: {:.2} MB, VMS: {:.2} MB, Peak: {:.2} MB", 
            memory_info.rss as f64 / 1024.0,
            memory_info.vms as f64 / 1024.0, 
            memory_info.peak as f64 / 1024.0
        );
    }
    
    for i in 0..iteration_count {
        let witness = compute_witness::<G1, G2>(
            current_public_input.clone(),
            private_inputs[i].clone(),
            witness_generator_file.clone(),
            &witness_generator_output,
        );

        // Reuse the circuit instance, only updating the witness
        reusable_circuit.witness = Some(witness);

        current_public_output = reusable_circuit.get_public_outputs();
        //println!("The generated public output after iteration {:?} is {:?}", i, current_public_output);
        //println!("The state for {:?} after iteration {:?} is {:?}", keyword, i, current_public_output);
        current_public_input = current_public_output
            .iter()
            .map(|&x| format!("{:?}", x).strip_prefix("0x").unwrap().to_string())
            .collect();

        let res = recursive_snark.prove_step(
            &pp,
            &reusable_circuit,
            &circuit_secondary,
            start_public_input.clone(),
            z0_secondary.clone(),
        );
        assert!(res.is_ok());
        
        // Print memory usage at the end of each iteration
        if let Some(memory_info) = get_memory_usage() {
            println!("Memory usage after iteration {}: RSS: {:.2} MB, VMS: {:.2} MB, Peak: {:.2} MB", 
                i, 
                memory_info.rss as f64 / 1024.0,
                memory_info.vms as f64 / 1024.0, 
                memory_info.peak as f64 / 1024.0
            );
        } else {
            println!("Could not read memory usage for iteration {}", i);
        }
    }
    //fs::remove_file(witness_generator_output)?;
    let fin_res = (current_public_output, recursive_snark, pp);
    println!("PublicParams creation took {:?}", pub_time);
    Ok(fin_res)
}

pub fn continue_recursive_circuit<G1, G2>(
    recursive_snark: &mut RecursiveSNARK<G1, G2, C1<G1>, C2<G2>>,
    last_zi: Vec<F<G1>>,
    witness_generator_file: FileLocation,
    r1cs: R1CS<F<G1>>,
    private_inputs: Vec<HashMap<String, Value>>,
    start_public_input: Vec<F<G1>>,
    pp: &PublicParams<G1, G2, C1<G1>, C2<G2>>,
) -> Result<(), std::io::Error>
    where
        G1: Group<Base = <G2 as Group>::Scalar>,
        G2: Group<Base = <G1 as Group>::Scalar>,
{
    let root = current_dir().unwrap();
    let witness_generator_output = root.join("circom_witness.wtns");

    let iteration_count = private_inputs.len();

    let mut current_public_input = last_zi
        .iter()
        .map(|&x| format!("{:?}", x).strip_prefix("0x").unwrap().to_string())
        .collect::<Vec<String>>();

    let circuit_secondary = TrivialTestCircuit::default();
    let z0_secondary = vec![G2::Scalar::ZERO];

    // Pre-allocate a single circuit instance to reuse throughout the loop
    let mut reusable_circuit = CircomCircuit {
        r1cs,  // Move the R1CS instead of cloning
        witness: None,
    };

    for i in 0..iteration_count {
        let witness = compute_witness::<G1, G2>(
            current_public_input.clone(),
            private_inputs[i].clone(),
            witness_generator_file.clone(),
            &witness_generator_output,
        );

        // Reuse the circuit instance, only updating the witness
        reusable_circuit.witness = Some(witness);

        let current_public_output = reusable_circuit.get_public_outputs();
        current_public_input = current_public_output
            .iter()
            .map(|&x| format!("{:?}", x).strip_prefix("0x").unwrap().to_string())
            .collect();

        let res = recursive_snark.prove_step(
            pp,
            &reusable_circuit,
            &circuit_secondary,
            start_public_input.clone(),
            z0_secondary.clone(),
        );

        assert!(res.is_ok());
    }

    fs::remove_file(witness_generator_output)?;

    Ok(())
}
