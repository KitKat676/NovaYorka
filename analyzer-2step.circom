pragma circom 2.0.0;
include "../cmu/circuits/regex_helpers.circom";

// “If step_in==a && next_char==b then out=c else out=d”
template IfElse(a, b, c, d) {
    signal input step_in;
    signal input next_char;
    signal output out;

    // 1 iff step_in == a
    component eqStep  = IsEqual();
    eqStep.in[0]      <== step_in;
    eqStep.in[1]      <== a;

    // 1 iff next_char == b
    component eqChar  = IsEqual();
    eqChar.in[0]      <== next_char;
    eqChar.in[1]      <== b;

    // pick c when eqChar.out==1, else d
    signal choice;
    choice           <== eqChar.out * c + (1 - eqChar.out) * d;

    // enable this branch only when eqStep.out==1
    out              <== eqStep.out * choice;
}

template StepMachine() {
    signal input step_in; //current state of DFA
    signal input next_char0; //input symbol
    signal input next_char1; //input symbol
    signal output step_out; //next state of DFA

	component br0 = IfElse(0, 102, 1, 0);
	component br1 = IfElse(1, 101, 2, 0);
	component br2 = IfElse(2, 116, 3, 0);
	component br3 = IfElse(3, 99, 4, 0);
	component br4 = IfElse(4, 104, 5, 0);
	component br5 = IfElse(5, 97, 5, 5);

    //signal next_char0, next_char1;
    //next_char1 <== next_char / 256;
    //next_char0 <== next_char - 256*next_char1;

	// connect the branches to the inputs
	br0.step_in <== step_in;
	br0.next_char <== next_char0;
	br1.step_in <== step_in;
	br1.next_char <== next_char0;
	br2.step_in <== step_in;
	br2.next_char <== next_char0;
	br3.step_in <== step_in;
	br3.next_char <== next_char0;
	br4.step_in <== step_in;
	br4.next_char <== next_char0;
	br5.step_in <== step_in;
	br5.next_char <== next_char0;

	signal step_out_temp <== br0.out + br1.out + br2.out + br3.out + br4.out + br5.out;

	component br01 = IfElse(0, 102, 1, 0);
    component br11 = IfElse(1, 101, 2, 0);
   	component br21 = IfElse(2, 116, 3, 0);
   	component br31 = IfElse(3, 99, 4, 0);
   	component br41 = IfElse(4, 104, 5, 0);
   	component br51 = IfElse(5, 97, 5, 5);

    // connect the branches to the inputs
   	br01.step_in <== step_out_temp;
   	br01.next_char <== next_char1;
   	br11.step_in <== step_out_temp;
   	br11.next_char <== next_char1;
    br21.step_in <== step_out_temp;
   	br21.next_char <== next_char1;
   	br31.step_in <== step_out_temp;
   	br31.next_char <== next_char1;
   	br41.step_in <== step_out_temp;
   	br41.next_char <== next_char1;
    br51.step_in <== step_out_temp;
    br51.next_char <== next_char1;

    step_out <== br01.out + br11.out + br21.out + br31.out + br41.out + br51.out;
	
}

component main {public [step_in] } = StepMachine();
/* component main { public [msg]} = Test(1); */