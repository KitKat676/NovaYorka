pragma circom 2.0.0;
include "../cmu/circuits/regex_helpers.circom";

template IfElse(a, b, c, d) {
    signal input step_in;
    signal input next_char;
    signal output out;

    component eqStep  = IsEqual();
    eqStep.in[0]      <== step_in;
    eqStep.in[1]      <== a;

    component eqChar  = IsEqual();
    eqChar.in[0]      <== next_char;
    eqChar.in[1]      <== b;

    signal choice;
    choice           <== eqChar.out * c + (1 - eqChar.out) * d;

    out              <== eqStep.out * choice;
}

template Step() {
    signal input step_in;
    signal input next_char;
    signal output step_out;

    component br0 = IfElse(0, 102, 1, 0);
    component br1 = IfElse(1, 101, 2, 0);
    component br2 = IfElse(2, 116, 3, 0);
    component br3 = IfElse(3, 99, 4, 0);
    component br4 = IfElse(4, 104, 5, 0);
    component br5 = IfElse(5, 97, 5, 5);

    br0.step_in <== step_in;
    br0.next_char <== next_char;
    br1.step_in <== step_in;
    br1.next_char <== next_char;
    br2.step_in <== step_in;
    br2.next_char <== next_char;
    br3.step_in <== step_in;
    br3.next_char <== next_char;
    br4.step_in <== step_in;
    br4.next_char <== next_char;
    br5.step_in <== step_in;
    br5.next_char <== next_char;

    step_out <== br0.out + br1.out + br2.out + br3.out + br4.out + br5.out;
}

template TenStepMachine() {
    signal input step_in;
    signal input next_char[10];
    signal output step_out;

    component step1 = Step();
    step1.step_in <== step_in;
    step1.next_char <== next_char[0];

    component step2 = Step();
    step2.step_in <== step1.step_out;
    step2.next_char <== next_char[1];

    component step3 = Step();
    step3.step_in <== step2.step_out;
    step3.next_char <== next_char[2];

    component step4 = Step();
    step4.step_in <== step3.step_out;
    step4.next_char <== next_char[3];

    component step5 = Step();
    step5.step_in <== step4.step_out;
    step5.next_char <== next_char[4];

    component step6 = Step();
    step6.step_in <== step5.step_out;
    step6.next_char <== next_char[5];

    component step7 = Step();
    step7.step_in <== step6.step_out;
    step7.next_char <== next_char[6];

    component step8 = Step();
    step8.step_in <== step7.step_out;
    step8.next_char <== next_char[7];

    component step9 = Step();
    step9.step_in <== step8.step_out;
    step9.next_char <== next_char[8];

    component step10 = Step();
    step10.step_in <== step9.step_out;
    step10.next_char <== next_char[9];

    step_out <== step10.step_out;
}

component main {public [step_in, next_char] } = TenStepMachine();