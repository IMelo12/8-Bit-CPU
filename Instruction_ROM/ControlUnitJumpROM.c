#include <stdio.h>
#include <string.h>

#define ALUI 0b10000000000000000000000  // ALU register in
#define FRI  0b01000000000000000000000  // Flags register in
#define HLT  0b00100000000000000000000  // Halt clock
#define MI   0b00010000000000000000000  // Memory address register in
#define RI   0b00001000000000000000000  // Ram in
#define RO   0b00000100000000000000000  // Ram out
#define IO   0b00000010000000000000000  // Instruction register in
#define II   0b00000001000000000000000  // Instrusction register out
#define AI   0b00000000100000000000000  // A register in
#define AO   0b00000000010000000000000  // A register out
#define ALUO 0b00000000001000000000000  // ALU register(accumulator) out
#define BI   0b00000000000100000000000  // B register in
#define OI   0b00000000000010000000000  // Output register in
#define CE   0b00000000000001000000000  // Counter(program counter) enable
#define CO   0b00000000000000100000000  // Counter(program counter) out
#define J    0b00000000000000010000000  // Jump(program counter)
#define SUB  0b00000000000000001000000  // Subtract enable
#define INC  0b00000000000000000100000  // Increment enable
#define DEC  0b00000000000000000010000  // Decrement enable
#define DECI 0b00000000000000000001000  // Decrement in
#define S0   0b00000000000000000000100  // ALU select bit S0
#define S1   0b00000000000000000000010  // ALU select bit S1
#define S2   0b00000000000000000000001  // ALU select bit S2

#define CF0  0
#define CF1  1

#define JMC 0b1111

// turns int into hex
void hex(char* binarystring, int number){
    sprintf(binarystring,"%X", number);
}


int main() {
    FILE *pf = fopen("decodeJUMP_ROM.txt", "w");
    if (pf == NULL) {
        perror("Failed to open file");
        return 1;
    }
     
    // template for instruction set
    int data[16][8] = {
        {MI|CO,  RO|II|CE,  0,      0,                                0,                            0,  0,  0},     // 0000 - NOP : no operation
        {MI|CO,  RO|II|CE,  IO|MI,  RO|AI,                            0,                            0,  0,  0},     // 0001 - LDA : load RAM value into 'A' register
        {MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                            ALUI|ALUO|AI|FRI,             0,  0,  0},     // 0010 - ADD : A + B
        {MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                            ALUI|ALUO|AI|SUB|S2|FRI,      0,  0,  0},     // 0011 - SUB : A - B
        {MI|CO,  RO|II|CE,  IO|MI,  AO|RI,                            0,                            0,  0,  0},     // 0100 - STA : stores register a in RAM
        {MI|CO,  RO|II|CE,  IO|AI,  0,                                0,                            0,  0,  0},     // 0101 - LDI : load value into 'A' register
        {MI|CO,  RO|II|CE,  IO|J,   0,                                0,                            0,  0,  0},     // 0110 - JMP : puts adress to jump to in program counter 
        {MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                            ALUI|ALUO|AI|S1|FRI,          0,  0,  0},     // 0111 - OR  : A OR B **
        {MI|CO,  RO|II|CE,  IO|MI,  ALUI|ALUO|S1|S2|AI|FRI,           0,                            0,  0,  0},     // 1000 - NOT : NOT A **
        {MI|CO,  RO|II|CE,  IO|MI,  ALUI|ALUO|S0|INC|AI|FRI,          0,                            0,  0,  0},     // 1001 - INC : increment **
        {MI|CO,  RO|II|CE,  IO|MI,  ALUI|ALUO|S0|S2|DEC|DECI|AI|FRI,  0,                            0,  0,  0},     // 1010 - DEC : decrement **
        {MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                            ALUI|ALUO|AI|S0|S1|FRI,       0,  0,  0},     // 1011 - XOR : A XOR B **
        {MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                            ALUI|ALUO|AI|S0|S1|S2|FRI,    0,  0,  0},     // 1100 - AND : A AND B **
        {MI|CO,  RO|II|CE,  AO|OI,  0,                                0,                            0,  0,  0},     // 1101 - OUT : load value into output register
        {MI|CO,  RO|II|CE,  HLT,    0,                                0,                            0,  0,  0},     // 1110 - HLT : stop program
        {MI|CO,  RO|II|CE,  0,      0,                                0,                            0,  0,  0}      // 1111 - JMC : Jump carry
    };
    // flag | Instruction | Step
    int program[2][16][8];

    // carry = 0
    memcpy(program[CF0], data, sizeof(data));
    // carry = 1 
    memcpy(program[CF1], data, sizeof(data));
    program[CF1][JMC][2] = IO|J; 

    int counter = 0;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<16; j++){
            for(int k = 0; k<8;k++ ){
                if(counter == 8){
                    fprintf(pf,"\n");
                    counter = 0;} 
                char binarystring[22];
                hex(binarystring,program[i][j][k]);
                fprintf(pf, "%s%s", binarystring," ");  
                counter ++;
            }
        }
    }
    
    fclose(pf);
    return 0;
}

