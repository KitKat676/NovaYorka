#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx);
void LessThan_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void LessThan_1_run(uint ctx_index,Circom_CalcWit* ctx);
void LessEqThan_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void LessEqThan_2_run(uint ctx_index,Circom_CalcWit* ctx);
void IsInRange_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsInRange_3_run(uint ctx_index,Circom_CalcWit* ctx);
void IsInRange_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsInRange_4_run(uint ctx_index,Circom_CalcWit* ctx);
void IsInRange_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsInRange_5_run(uint ctx_index,Circom_CalcWit* ctx);
void IsZero_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsZero_6_run(uint ctx_index,Circom_CalcWit* ctx);
void IsEqual_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsEqual_7_run(uint ctx_index,Circom_CalcWit* ctx);
void IsAlphanumeric_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsAlphanumeric_8_run(uint ctx_index,Circom_CalcWit* ctx);
void Step_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Step_9_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[10] = { 
Num2Bits_0_run,
LessThan_1_run,
LessEqThan_2_run,
IsInRange_3_run,
IsInRange_4_run,
IsInRange_5_run,
IsZero_6_run,
IsEqual_7_run,
IsAlphanumeric_8_run,
Step_9_run };
Circom_TemplateFunction _functionTableParallel[10] = { 
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL };
uint get_main_input_signal_start() {return 17;}

uint get_main_input_signal_no() {return 17;}

uint get_total_signal_no() {return 861;}

uint get_number_of_components() {return 159;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 642;}

uint get_size_of_constants() {return 26;}

uint get_size_of_io_map() {return 0;}

uint get_size_of_bus_field_map() {return 0;}

void release_memory_component(Circom_CalcWit* ctx, uint pos) {{

if (pos != 0){{

if(ctx->componentMemory[pos].subcomponents)
delete []ctx->componentMemory[pos].subcomponents;

if(ctx->componentMemory[pos].subcomponentsParallel)
delete []ctx->componentMemory[pos].subcomponentsParallel;

if(ctx->componentMemory[pos].outputIsSet)
delete []ctx->componentMemory[pos].outputIsSet;

if(ctx->componentMemory[pos].mutexes)
delete []ctx->componentMemory[pos].mutexes;

if(ctx->componentMemory[pos].cvs)
delete []ctx->componentMemory[pos].cvs;

if(ctx->componentMemory[pos].sbct)
delete []ctx->componentMemory[pos].sbct;

}}


}}


// function declarations
// template declarations
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[4];
FrElement lvar[4];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 31
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)];
// load src
Fr_shr(&expaux[1],&signalValues[mySignalStart + 17],&lvar[3]); // line circom 32
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 32
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
Fr_sub(&expaux[2],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&circuitConstants[2]); // line circom 33
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&expaux[2]); // line circom 33
{{
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 33
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&lvar[2]); // line circom 34
Fr_add(&expaux[0],&lvar[1],&expaux[1]); // line circom 34
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&lvar[2]); // line circom 35
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
Fr_add(&expaux[0],&lvar[3],&circuitConstants[2]); // line circom 31
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 31
}
{
{{
Fr_eq(&expaux[0],&lvar[1],&signalValues[mySignalStart + 17]); // line circom 38
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 38. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void LessThan_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "LessThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessThan_1_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[3];
FrElement lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
std::string new_cmp_name = "n2b";
Num2Bits_0_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
if (!Fr_isTrue(&circuitConstants[2])) std::cout << "Failed assert in template/function " << myTemplateName << " line 90. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&circuitConstants[2]));
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 17];
// load src
Fr_add(&expaux[1],&signalValues[mySignalStart + 1],&circuitConstants[4]); // line circom 96
Fr_sub(&expaux[0],&expaux[1],&signalValues[mySignalStart + 2]); // line circom 96
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
Fr_sub(&expaux[0],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 16]); // line circom 98
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void LessEqThan_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "LessEqThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessEqThan_2_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[2];
FrElement lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
std::string new_cmp_name = "lt";
LessThan_1_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
Fr_add(&expaux[0],&signalValues[mySignalStart + 2],&circuitConstants[2]); // line circom 112
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void IsInRange_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 3;
ctx->componentMemory[coffset].templateName = "IsInRange";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[2]{0};
}

void IsInRange_3_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[1];
FrElement lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[6]);
}
{
std::string new_cmp_name = "ch1";
LessEqThan_2_create(mySignalStart+2,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
std::string new_cmp_name = "ch2";
LessEqThan_2_create(mySignalStart+26,3+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[1] = 3+ctx_index+1;
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[6]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessEqThan_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessEqThan_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
cmp_index_ref_load = 1;
cmp_index_ref_load = 1;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
for (uint i = 0; i < 2; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void IsInRange_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 4;
ctx->componentMemory[coffset].templateName = "IsInRange";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[2]{0};
}

void IsInRange_4_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[1];
FrElement lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[7]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[8]);
}
{
std::string new_cmp_name = "ch1";
LessEqThan_2_create(mySignalStart+2,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
std::string new_cmp_name = "ch2";
LessEqThan_2_create(mySignalStart+26,3+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[1] = 3+ctx_index+1;
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[8]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessEqThan_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[7]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessEqThan_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
cmp_index_ref_load = 1;
cmp_index_ref_load = 1;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
for (uint i = 0; i < 2; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void IsInRange_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 5;
ctx->componentMemory[coffset].templateName = "IsInRange";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[2]{0};
}

void IsInRange_5_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[1];
FrElement lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[9]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[10]);
}
{
std::string new_cmp_name = "ch1";
LessEqThan_2_create(mySignalStart+2,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
std::string new_cmp_name = "ch2";
LessEqThan_2_create(mySignalStart+26,3+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[1] = 3+ctx_index+1;
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[10]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessEqThan_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[9]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessEqThan_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
cmp_index_ref_load = 1;
cmp_index_ref_load = 1;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
for (uint i = 0; i < 2; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void IsZero_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 6;
ctx->componentMemory[coffset].templateName = "IsZero";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void IsZero_6_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[3];
FrElement lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
Fr_neq(&expaux[0],&signalValues[mySignalStart + 1],&circuitConstants[1]); // line circom 30
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + 2];
// load src
Fr_div(&expaux[0],&circuitConstants[2],&signalValues[mySignalStart + 1]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}else{
{
PFrElement aux_dest = &signalValues[mySignalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
Fr_neg(&expaux[2],&signalValues[mySignalStart + 1]); // line circom 32
Fr_mul(&expaux[1],&expaux[2],&signalValues[mySignalStart + 2]); // line circom 32
Fr_add(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 32
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
Fr_mul(&expaux[1],&signalValues[mySignalStart + 1],&signalValues[mySignalStart + 0]); // line circom 33
{{
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 33
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void IsEqual_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 7;
ctx->componentMemory[coffset].templateName = "IsEqual";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void IsEqual_7_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[1];
FrElement lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "isz";
IsZero_6_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
Fr_sub(&expaux[0],&signalValues[mySignalStart + 2],&signalValues[mySignalStart + 1]); // line circom 43
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsZero_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void IsAlphanumeric_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 8;
ctx->componentMemory[coffset].templateName = "IsAlphanumeric";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[4]{0};
}

void IsAlphanumeric_8_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[3];
FrElement lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "check_lower";
IsInRange_3_create(mySignalStart+52,7+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 7+ctx_index+1;
}
{
std::string new_cmp_name = "check_upper";
IsInRange_4_create(mySignalStart+102,14+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[1] = 14+ctx_index+1;
}
{
std::string new_cmp_name = "check_digit";
IsInRange_5_create(mySignalStart+2,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[2] = 0+ctx_index+1;
}
{
std::string new_cmp_name = "check_uscore";
IsEqual_7_create(mySignalStart+152,21+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[3] = 21+ctx_index+1;
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsInRange_3_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsInRange_4_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 2;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsInRange_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 3;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 3;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[11]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
cmp_index_ref_load = 1;
cmp_index_ref_load = 1;
Fr_add(&expaux[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0]); // line circom 53
cmp_index_ref_load = 2;
cmp_index_ref_load = 2;
Fr_add(&expaux[1],&expaux[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + 0]); // line circom 53
cmp_index_ref_load = 3;
cmp_index_ref_load = 3;
Fr_add(&expaux[0],&expaux[1],&ctx->signalValues[ctx->componentMemory[mySubcomponents[3]].signalStart + 0]); // line circom 53
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
for (uint i = 0; i < 4; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Step_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 9;
ctx->componentMemory[coffset].templateName = "Step";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 17;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[68]{0};
}

void Step_9_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement* signalValues = ctx->signalValues;
FrElement expaux[5];
FrElement lvar[12];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
uint aux_create = 0;
int aux_cmp_num = 64+ctx_index+1;
uint csoffset = mySignalStart+428;
uint aux_dimensions[1] = {10};
for (uint i = 0; i < 10; i++) {
std::string new_cmp_name = "is_match_char"+ctx->generate_position_array(aux_dimensions, 1, i);
IsEqual_7_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 6 ;
aux_cmp_num += 2;
}
}
{
uint aux_create = 10;
int aux_cmp_num = 84+ctx_index+1;
uint csoffset = mySignalStart+488;
uint aux_dimensions[1] = {16};
for (uint i = 0; i < 16; i++) {
std::string new_cmp_name = "is_match_state"+ctx->generate_position_array(aux_dimensions, 1, i);
IsEqual_7_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 6 ;
aux_cmp_num += 2;
}
}
{
std::string new_cmp_name = "is_anum";
IsAlphanumeric_8_create(mySignalStart+252,34+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[26] = 34+ctx_index+1;
}
{
std::string new_cmp_name = "is_slash";
IsEqual_7_create(mySignalStart+584,116+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[27] = 116+ctx_index+1;
}
{
std::string new_cmp_name = "is_CR";
IsEqual_7_create(mySignalStart+234,28+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[28] = 28+ctx_index+1;
}
{
std::string new_cmp_name = "is_SQ";
IsEqual_7_create(mySignalStart+246,32+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[29] = 32+ctx_index+1;
}
{
std::string new_cmp_name = "is_backsl";
IsEqual_7_create(mySignalStart+410,58+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[30] = 58+ctx_index+1;
}
{
std::string new_cmp_name = "is_star";
IsEqual_7_create(mySignalStart+590,118+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[31] = 118+ctx_index+1;
}
{
std::string new_cmp_name = "is_DQ";
IsEqual_7_create(mySignalStart+240,30+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[32] = 30+ctx_index+1;
}
{
std::string new_cmp_name = "is_bt";
IsEqual_7_create(mySignalStart+416,60+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[33] = 60+ctx_index+1;
}
{
std::string new_cmp_name = "eq_cmt";
IsEqual_7_create(mySignalStart+210,20+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[34] = 20+ctx_index+1;
}
{
std::string new_cmp_name = "eq_qut";
IsEqual_7_create(mySignalStart+228,26+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[35] = 26+ctx_index+1;
}
{
std::string new_cmp_name = "eq_mlcmt";
IsEqual_7_create(mySignalStart+222,24+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[36] = 24+ctx_index+1;
}
{
std::string new_cmp_name = "eq_dqt";
IsEqual_7_create(mySignalStart+216,22+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[37] = 22+ctx_index+1;
}
{
std::string new_cmp_name = "eq_bkt";
IsEqual_7_create(mySignalStart+204,18+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[38] = 18+ctx_index+1;
}
{
uint aux_create = 39;
int aux_cmp_num = 124+ctx_index+1;
uint csoffset = mySignalStart+608;
uint aux_dimensions[1] = {10};
for (uint i = 0; i < 10; i++) {
std::string new_cmp_name = "length_check"+ctx->generate_position_array(aux_dimensions, 1, i);
LessThan_1_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+ i] = aux_cmp_num;
csoffset += 21 ;
aux_cmp_num += 2;
}
}
{
std::string new_cmp_name = "is_state_after_match";
IsEqual_7_create(mySignalStart+602,122+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[49] = 122+ctx_index+1;
}
{
std::string new_cmp_name = "is_holding";
IsEqual_7_create(mySignalStart+422,62+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[50] = 62+ctx_index+1;
}
{
std::string new_cmp_name = "is_state_accept";
IsEqual_7_create(mySignalStart+596,120+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[51] = 120+ctx_index+1;
}
{
std::string new_cmp_name = "cmteol_st_0";
IsEqual_7_create(mySignalStart+168,6+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[52] = 6+ctx_index+1;
}
{
std::string new_cmp_name = "cmteol_st_1";
IsEqual_7_create(mySignalStart+174,8+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[53] = 8+ctx_index+1;
}
{
std::string new_cmp_name = "cmteol_st_2";
IsEqual_7_create(mySignalStart+180,10+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[54] = 10+ctx_index+1;
}
{
std::string new_cmp_name = "sq_st_0";
IsEqual_7_create(mySignalStart+842,152+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[55] = 152+ctx_index+1;
}
{
std::string new_cmp_name = "sq_st_1";
IsEqual_7_create(mySignalStart+848,154+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[56] = 154+ctx_index+1;
}
{
std::string new_cmp_name = "sq_st_2";
IsEqual_7_create(mySignalStart+854,156+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[57] = 156+ctx_index+1;
}
{
std::string new_cmp_name = "mlcmt_st_0";
IsEqual_7_create(mySignalStart+818,144+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[58] = 144+ctx_index+1;
}
{
std::string new_cmp_name = "mlcmt_st_1";
IsEqual_7_create(mySignalStart+824,146+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[59] = 146+ctx_index+1;
}
{
std::string new_cmp_name = "mlcmt_st_2";
IsEqual_7_create(mySignalStart+830,148+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[60] = 148+ctx_index+1;
}
{
std::string new_cmp_name = "mlcmt_st_3";
IsEqual_7_create(mySignalStart+836,150+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[61] = 150+ctx_index+1;
}
{
std::string new_cmp_name = "dq_st_0";
IsEqual_7_create(mySignalStart+186,12+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[62] = 12+ctx_index+1;
}
{
std::string new_cmp_name = "dq_st_1";
IsEqual_7_create(mySignalStart+192,14+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[63] = 14+ctx_index+1;
}
{
std::string new_cmp_name = "dq_st_2";
IsEqual_7_create(mySignalStart+198,16+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[64] = 16+ctx_index+1;
}
{
std::string new_cmp_name = "bt_st_0";
IsEqual_7_create(mySignalStart+150,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[65] = 0+ctx_index+1;
}
{
std::string new_cmp_name = "bt_st_1";
IsEqual_7_create(mySignalStart+156,2+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[66] = 2+ctx_index+1;
}
{
std::string new_cmp_name = "bt_st_2";
IsEqual_7_create(mySignalStart+162,4+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[67] = 4+ctx_index+1;
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[12]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 16]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 17]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 32]);
}
{
uint cmp_index_ref = 26;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsAlphanumeric_8_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[4];
// load src
cmp_index_ref_load = 26;
cmp_index_ref_load = 26;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[26]].signalStart + 0]);
}
{
uint cmp_index_ref = 27;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 27;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[13]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 28;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 28;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[12]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 29;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 29;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[14]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 30;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 30;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[15]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 31;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 31;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[16]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 32;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 32;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[17]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 33;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 33;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[18]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 34;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 27]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 34;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[5];
// load src
cmp_index_ref_load = 34;
cmp_index_ref_load = 34;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[34]].signalStart + 0]);
}
{
uint cmp_index_ref = 35;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 28]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 35;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[6];
// load src
cmp_index_ref_load = 35;
cmp_index_ref_load = 35;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[35]].signalStart + 0]);
}
{
uint cmp_index_ref = 36;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 29]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 36;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[7];
// load src
cmp_index_ref_load = 36;
cmp_index_ref_load = 36;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[36]].signalStart + 0]);
}
{
uint cmp_index_ref = 37;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 30]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 37;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[8];
// load src
cmp_index_ref_load = 37;
cmp_index_ref_load = 37;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[37]].signalStart + 0]);
}
{
uint cmp_index_ref = 38;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 31]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 38;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[9];
// load src
cmp_index_ref_load = 38;
cmp_index_ref_load = 38;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[38]].signalStart + 0]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[10],&circuitConstants[12]); // line circom 99
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[10])) + 39);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[1]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
LessThan_1_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[10])) + 39);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[2]); // line circom 102
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
LessThan_1_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[10];
// load src
Fr_add(&expaux[0],&lvar[10],&circuitConstants[2]); // line circom 99
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[10],&circuitConstants[12]); // line circom 99
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[10],&circuitConstants[12]); // line circom 105
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[10])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[10])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[10]) + 2)) + 16)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[10];
// load src
Fr_add(&expaux[0],&lvar[10],&circuitConstants[2]); // line circom 105
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[10],&circuitConstants[12]); // line circom 105
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[10],&circuitConstants[3]); // line circom 111
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[10])) + 10);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[10]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[10])) + 10);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&lvar[1]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[10];
// load src
Fr_add(&expaux[0],&lvar[10],&circuitConstants[2]); // line circom 111
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[10],&circuitConstants[3]); // line circom 111
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[11],&circuitConstants[12]); // line circom 121
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 33)];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 10);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 10);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 0);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 0);
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[11])) + 10)]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[11])) + 0)]].signalStart + 0]); // line circom 122
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 43)];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 39);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 39);
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 33)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[11])) + 39)]].signalStart + 0]); // line circom 123
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 53)];
// load src
Fr_add(&expaux[1],&lvar[11],&circuitConstants[2]); // line circom 124
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 43)],&expaux[1]); // line circom 124
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
Fr_add(&expaux[0],&lvar[10],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 53)]); // line circom 125
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[11];
// load src
Fr_add(&expaux[0],&lvar[11],&circuitConstants[2]); // line circom 121
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[11],&circuitConstants[12]); // line circom 121
}
{
PFrElement aux_dest = &lvar[11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[11],&circuitConstants[12]); // line circom 132
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 63)];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 10);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 10);
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[11])) + 10)]].signalStart + 0],&lvar[4]); // line circom 133
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 73)];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 0);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 0);
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[11])) + 0)]].signalStart + 0]); // line circom 134
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 63)],&expaux[1]); // line circom 134
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 83)];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 39);
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[11])) + 39);
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 73)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[11])) + 39)]].signalStart + 0]); // line circom 135
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 93)];
// load src
Fr_add(&expaux[1],&lvar[2],&circuitConstants[20]); // line circom 136
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 83)],&expaux[1]); // line circom 136
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
Fr_add(&expaux[0],&lvar[10],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 93)]); // line circom 137
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[11];
// load src
Fr_add(&expaux[0],&lvar[11],&circuitConstants[2]); // line circom 132
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[11],&circuitConstants[12]); // line circom 132
}
{
uint cmp_index_ref = 49;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 49;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&lvar[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 103];
// load src
cmp_index_ref_load = 49;
cmp_index_ref_load = 49;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[49]].signalStart + 0],&lvar[4]); // line circom 145
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 104];
// load src
Fr_add(&expaux[1],&lvar[2],&circuitConstants[20]); // line circom 146
Fr_mul(&expaux[0],&signalValues[mySignalStart + 103],&expaux[1]); // line circom 146
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
uint cmp_index_ref = 50;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 50;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[20]); // line circom 152
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 105];
// load src
cmp_index_ref_load = 50;
cmp_index_ref_load = 50;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[50]].signalStart + 0],&lvar[4]); // line circom 153
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 106];
// load src
Fr_add(&expaux[1],&lvar[2],&circuitConstants[20]); // line circom 154
Fr_mul(&expaux[0],&signalValues[mySignalStart + 105],&expaux[1]); // line circom 154
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
Fr_add(&expaux[0],&lvar[10],&signalValues[mySignalStart + 106]); // line circom 155
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 107];
// load src
cmp_index_ref_load = 49;
cmp_index_ref_load = 49;
Fr_sub(&expaux[1],&circuitConstants[2],&lvar[4]); // line circom 159
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[49]].signalStart + 0],&expaux[1]); // line circom 159
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 108];
// load src
Fr_add(&expaux[1],&lvar[2],&circuitConstants[2]); // line circom 160
Fr_mul(&expaux[0],&signalValues[mySignalStart + 107],&expaux[1]); // line circom 160
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
Fr_add(&expaux[0],&lvar[10],&signalValues[mySignalStart + 108]); // line circom 161
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
uint cmp_index_ref = 51;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&lvar[1]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 51;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[2]); // line circom 167
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 109];
// load src
cmp_index_ref_load = 51;
cmp_index_ref_load = 51;
Fr_add(&expaux[1],&lvar[2],&circuitConstants[2]); // line circom 168
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[51]].signalStart + 0],&expaux[1]); // line circom 168
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
Fr_add(&expaux[0],&lvar[10],&signalValues[mySignalStart + 109]); // line circom 169
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&lvar[10]);
}
{
PFrElement aux_dest = &lvar[11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
Fr_leq(&expaux[0],&lvar[11],&circuitConstants[12]); // line circom 171
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 0)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[11])) + 16)]);
}
{
PFrElement aux_dest = &lvar[11];
// load src
Fr_add(&expaux[0],&lvar[11],&circuitConstants[2]); // line circom 171
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_leq(&expaux[0],&lvar[11],&circuitConstants[12]); // line circom 171
}
{
uint cmp_index_ref = 52;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 27]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 52;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 53;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 27]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 53;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 54;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 27]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 54;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 110];
// load src
cmp_index_ref_load = 52;
cmp_index_ref_load = 52;
cmp_index_ref_load = 27;
cmp_index_ref_load = 27;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[52]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[27]].signalStart + 0]); // line circom 181
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 111];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 110],&circuitConstants[2]); // line circom 182
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 112];
// load src
cmp_index_ref_load = 53;
cmp_index_ref_load = 53;
cmp_index_ref_load = 27;
cmp_index_ref_load = 27;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[53]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[27]].signalStart + 0]); // line circom 184
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 113];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 112],&circuitConstants[20]); // line circom 185
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 114];
// load src
cmp_index_ref_load = 54;
cmp_index_ref_load = 54;
cmp_index_ref_load = 28;
cmp_index_ref_load = 28;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[28]].signalStart + 0]); // line circom 187
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[54]].signalStart + 0],&expaux[1]); // line circom 187
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 115];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 114],&circuitConstants[20]); // line circom 188
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 11];
// load src
Fr_add(&expaux[1],&signalValues[mySignalStart + 111],&signalValues[mySignalStart + 113]); // line circom 191
Fr_add(&expaux[0],&expaux[1],&signalValues[mySignalStart + 115]); // line circom 191
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
uint cmp_index_ref = 55;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 28]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 55;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 56;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 28]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 56;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 57;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 28]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 57;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 116];
// load src
cmp_index_ref_load = 55;
cmp_index_ref_load = 55;
cmp_index_ref_load = 29;
cmp_index_ref_load = 29;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[55]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[29]].signalStart + 0]); // line circom 200
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 117];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 116],&circuitConstants[2]); // line circom 201
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 118];
// load src
cmp_index_ref_load = 56;
cmp_index_ref_load = 56;
cmp_index_ref_load = 30;
cmp_index_ref_load = 30;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[56]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[30]].signalStart + 0]); // line circom 203
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 119];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 118],&circuitConstants[20]); // line circom 204
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 120];
// load src
cmp_index_ref_load = 57;
cmp_index_ref_load = 57;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[57]].signalStart + 0],&circuitConstants[2]); // line circom 206
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 121];
// load src
cmp_index_ref_load = 56;
cmp_index_ref_load = 56;
cmp_index_ref_load = 30;
cmp_index_ref_load = 30;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[30]].signalStart + 0]); // line circom 208
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[56]].signalStart + 0],&expaux[1]); // line circom 208
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 122];
// load src
cmp_index_ref_load = 29;
cmp_index_ref_load = 29;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[29]].signalStart + 0]); // line circom 209
Fr_mul(&expaux[0],&signalValues[mySignalStart + 121],&expaux[1]); // line circom 209
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 12];
// load src
Fr_add(&expaux[2],&signalValues[mySignalStart + 117],&signalValues[mySignalStart + 119]); // line circom 212
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 120]); // line circom 212
Fr_add(&expaux[0],&expaux[1],&signalValues[mySignalStart + 122]); // line circom 212
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
uint cmp_index_ref = 58;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 29]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 58;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 59;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 29]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 59;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 60;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 29]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 60;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 61;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 29]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 61;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[25]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 123];
// load src
cmp_index_ref_load = 58;
cmp_index_ref_load = 58;
cmp_index_ref_load = 27;
cmp_index_ref_load = 27;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[58]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[27]].signalStart + 0]); // line circom 222
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 124];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 123],&circuitConstants[2]); // line circom 223
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 125];
// load src
cmp_index_ref_load = 59;
cmp_index_ref_load = 59;
cmp_index_ref_load = 31;
cmp_index_ref_load = 31;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[59]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[31]].signalStart + 0]); // line circom 225
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 126];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 125],&circuitConstants[20]); // line circom 226
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 127];
// load src
cmp_index_ref_load = 60;
cmp_index_ref_load = 60;
cmp_index_ref_load = 31;
cmp_index_ref_load = 31;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[31]].signalStart + 0]); // line circom 228
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[60]].signalStart + 0],&expaux[1]); // line circom 228
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 128];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 127],&circuitConstants[20]); // line circom 229
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 129];
// load src
cmp_index_ref_load = 60;
cmp_index_ref_load = 60;
cmp_index_ref_load = 31;
cmp_index_ref_load = 31;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[60]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[31]].signalStart + 0]); // line circom 231
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 130];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 129],&circuitConstants[25]); // line circom 232
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 131];
// load src
cmp_index_ref_load = 61;
cmp_index_ref_load = 61;
cmp_index_ref_load = 31;
cmp_index_ref_load = 31;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[31]].signalStart + 0]); // line circom 234
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[61]].signalStart + 0],&expaux[1]); // line circom 234
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 132];
// load src
cmp_index_ref_load = 27;
cmp_index_ref_load = 27;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[27]].signalStart + 0]); // line circom 235
Fr_mul(&expaux[0],&signalValues[mySignalStart + 131],&expaux[1]); // line circom 235
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 133];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 132],&circuitConstants[20]); // line circom 236
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 134];
// load src
cmp_index_ref_load = 61;
cmp_index_ref_load = 61;
cmp_index_ref_load = 31;
cmp_index_ref_load = 31;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[61]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[31]].signalStart + 0]); // line circom 238
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 135];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 134],&circuitConstants[25]); // line circom 239
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 13];
// load src
Fr_add(&expaux[4],&signalValues[mySignalStart + 124],&signalValues[mySignalStart + 126]); // line circom 242
Fr_add(&expaux[3],&expaux[4],&signalValues[mySignalStart + 128]); // line circom 242
Fr_add(&expaux[2],&expaux[3],&signalValues[mySignalStart + 130]); // line circom 242
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 133]); // line circom 242
Fr_add(&expaux[0],&expaux[1],&signalValues[mySignalStart + 135]); // line circom 242
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
uint cmp_index_ref = 62;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 30]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 62;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 63;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 30]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 63;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 64;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 30]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 64;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 136];
// load src
cmp_index_ref_load = 62;
cmp_index_ref_load = 62;
cmp_index_ref_load = 32;
cmp_index_ref_load = 32;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[62]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[32]].signalStart + 0]); // line circom 250
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 137];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 136],&circuitConstants[2]); // line circom 251
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 138];
// load src
cmp_index_ref_load = 63;
cmp_index_ref_load = 63;
cmp_index_ref_load = 30;
cmp_index_ref_load = 30;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[63]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[30]].signalStart + 0]); // line circom 253
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 139];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 138],&circuitConstants[20]); // line circom 254
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 140];
// load src
cmp_index_ref_load = 64;
cmp_index_ref_load = 64;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[64]].signalStart + 0],&circuitConstants[2]); // line circom 256
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 141];
// load src
cmp_index_ref_load = 63;
cmp_index_ref_load = 63;
cmp_index_ref_load = 30;
cmp_index_ref_load = 30;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[30]].signalStart + 0]); // line circom 258
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[63]].signalStart + 0],&expaux[1]); // line circom 258
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 142];
// load src
cmp_index_ref_load = 32;
cmp_index_ref_load = 32;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[32]].signalStart + 0]); // line circom 259
Fr_mul(&expaux[0],&signalValues[mySignalStart + 141],&expaux[1]); // line circom 259
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 14];
// load src
Fr_add(&expaux[2],&signalValues[mySignalStart + 137],&signalValues[mySignalStart + 139]); // line circom 262
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 140]); // line circom 262
Fr_add(&expaux[0],&expaux[1],&signalValues[mySignalStart + 142]); // line circom 262
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
uint cmp_index_ref = 65;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 31]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 65;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 66;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 31]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 66;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 67;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 31]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 67;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 143];
// load src
cmp_index_ref_load = 65;
cmp_index_ref_load = 65;
cmp_index_ref_load = 33;
cmp_index_ref_load = 33;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[65]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[33]].signalStart + 0]); // line circom 270
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 144];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 143],&circuitConstants[2]); // line circom 271
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 145];
// load src
cmp_index_ref_load = 66;
cmp_index_ref_load = 66;
cmp_index_ref_load = 30;
cmp_index_ref_load = 30;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[66]].signalStart + 0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[30]].signalStart + 0]); // line circom 273
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 146];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 145],&circuitConstants[20]); // line circom 274
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 147];
// load src
cmp_index_ref_load = 67;
cmp_index_ref_load = 67;
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[67]].signalStart + 0],&circuitConstants[2]); // line circom 276
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 148];
// load src
cmp_index_ref_load = 66;
cmp_index_ref_load = 66;
cmp_index_ref_load = 30;
cmp_index_ref_load = 30;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[30]].signalStart + 0]); // line circom 278
Fr_mul(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[66]].signalStart + 0],&expaux[1]); // line circom 278
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 149];
// load src
cmp_index_ref_load = 33;
cmp_index_ref_load = 33;
Fr_sub(&expaux[1],&circuitConstants[2],&ctx->signalValues[ctx->componentMemory[mySubcomponents[33]].signalStart + 0]); // line circom 279
Fr_mul(&expaux[0],&signalValues[mySignalStart + 148],&expaux[1]); // line circom 279
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 15];
// load src
Fr_add(&expaux[2],&signalValues[mySignalStart + 144],&signalValues[mySignalStart + 146]); // line circom 282
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 147]); // line circom 282
Fr_add(&expaux[0],&expaux[1],&signalValues[mySignalStart + 149]); // line circom 282
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
for (uint i = 0; i < 68; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
Step_9_create(1,0,ctx,"main",0);
Step_9_run(0,ctx);
}

