// ffi.rs

use std::ffi::{CStr, CString};
use std::os::raw::{c_char, c_void};

#[repr(C)]
pub struct CircomCircuit;

#[repr(C)]
pub struct CircomCalcWit;

extern "C" {
    pub fn load_circuit(dat_path: *const c_char) -> *mut CircomCircuit;
    pub fn destroy_circuit(c: *mut CircomCircuit);

    pub fn create_ctx(circuit: *mut CircomCircuit) -> *mut CircomCalcWit;
    pub fn destroy_ctx(ctx: *mut CircomCalcWit);

    pub fn load_json_from_str(
        ctx: *mut CircomCalcWit,
        json_str: *const c_char,
        err_msg_out: *mut *mut c_char,
    ) -> bool;

    pub fn write_witness_to_file(
        ctx: *mut CircomCalcWit,
        output_path: *const c_char,
        err_msg_out: *mut *mut c_char,
    ) -> bool;

    pub fn free_err_msg(msg: *mut c_char);
}
