/* 
    Older iteration of ROM for control unit 
    See 'ControlUnitJumpROM.c' for updated control unit ROM

*/

#include <stdio.h>


#define HLT 0b100000000000000000000
#define MI 0b010000000000000000000
#define RI 0b001000000000000000000
#define RO 0b000100000000000000000
#define IO 0b000010000000000000000
#define II 0b000001000000000000000
#define AI 0b000000100000000000000
#define AO 0b000000010000000000000
#define ALUO 0b000000001000000000000
#define BI 0b000000000100000000000
#define OI 0b000000000010000000000
#define CE 0b000000000001000000000
#define CO 0b000000000000100000000
#define J 0b000000000000010000000
#define SUB 0b000000000000001000000
#define INC 0b000000000000000100000
#define DEC 0b000000000000000010000
#define DECI 0b000000000000000001000
#define S0 0b000000000000000000100
#define S1 0b000000000000000000010
#define S2 0b000000000000000000001


void hex(char* binarystring, int number){
    sprintf(binarystring,"%X", number);
}


int main() {
    FILE *pf = fopen("decodeROM.txt", "w");
    if (pf == NULL) {
        perror("Failed to open file");
        return 1;
    }
    // Add jump carry instruction
    int data[] = {
        MI|CO,  RO|II|CE,  0,      0,                       0,                 0,  0,  0,     // 0000 - NOP : no operation
        MI|CO,  RO|II|CE,  IO|MI,  RO|AI,                   0,                 0,  0,  0,     // 0001 - LDA : load RAM value into 'A' register
        MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                   ALUO|AI,           0,  0,  0,     // 0010 - ADD : A + B
        MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                   ALUO|AI|SUB|S2,    0,  0,  0,     // 0011 - SUB : A - B
        MI|CO,  RO|II|CE,  IO|MI,  AO|RI,                   0,                 0,  0,  0,     // 0100 - STA : stores register a in RAM
        MI|CO,  RO|II|CE,  IO|AI,  0,                       0,                 0,  0,  0,     // 0101 - LDI : load value into 'A' register
        MI|CO,  RO|II|CE,  IO|J,   0,                       0,                 0,  0,  0,     // 0110 - JMP : puts adress to jump to in program counter 
        MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                   ALUO|AI|S1,        0,  0,  0,     // 0111 - OR  : A OR B **
        MI|CO,  RO|II|CE,  IO|MI,  ALUO|S1|S2|AI,           0,                 0,  0,  0,     // 1000 - NOT : NOT A **
        MI|CO,  RO|II|CE,  IO|MI,  ALUO|S0|INC|AI,          0,                 0,  0,  0,     // 1001 - INC : increment **
        MI|CO,  RO|II|CE,  IO|MI,  ALUO|S0|S2|DEC|DECI|AI,  0,                 0,  0,  0,     // 1010 - DEC : decrement **
        MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                   ALUO|AI|S0|S1,     0,  0,  0,     // 1011 - XOR : A XOR B **
        MI|CO,  RO|II|CE,  IO|MI,  RO|BI,                   ALUO|AI|S0|S1|S2,  0,  0,  0,     // 1100 - AND : A AND B **
        MI|CO,  RO|II|CE,  AO|OI,  0,                       0,                 0,  0,  0,     // 1101 - OUT : load value into output register
        MI|CO,  RO|II|CE,  HLT,    0,                       0,                 0,  0,  0,     // 1110 - HLT : stop program
    };

    
    int size = sizeof(data) / sizeof(data[0]);
    int counter = 0;
    
    for (int i = 0; i < size; i++) {
        if(counter == 8){
            fprintf(pf,"\n");
            counter = 0;
        }
        char binaryString[22];  
        hex(binaryString,data[i]);

        fprintf(pf, "%s%s", binaryString," ");  
        counter ++;
    }
    

    fclose(pf);

    return 0;
}