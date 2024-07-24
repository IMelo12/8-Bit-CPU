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
#define SO 0b000000000000000000100
#define S1 0b000000000000000000010
#define S2 0b000000000000000000001

// Function to convert an integer to a binary string
void printBinary(int number, char* binaryString) {
    for (int i = 20; i >= 0; i--) {
        binaryString[20 - i] = ((number >> i) & 1) + '0';  // Fixed indexing to match 21 bits
    }
    binaryString[21] = '\0';  // Null-terminate the string
}

void sixbithex(int number, char* binaryString){
    for (int i = 5; i >= 0; i--) {
        binaryString[5 - i] =((number >> i) & 1) + '0';  // Fixed indexing to match 21 bits
    }
    binaryString[6] = '\0';  // Null-terminate the string
}

int main() {
    FILE *pf = fopen("decodeROM.txt", "w");
    if (pf == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int data[] = {
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0000 - NOP
        MI|CO, RO|II|CE, IO|MI, RO|AI, 0,       0,0,0,     // 0001 - LDA
        MI|CO, RO|II|CE, IO|MI, RO|BI, ALUO|AI, 0,0,0,     // 0010 - ADD *
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, 0,     0,     0,       0,0,0,     // 0011 - 
        MI|CO, RO|II|CE, AO|OI, 0,     0,       0,0,0,     // 1110 - OUT
        MI|CO, RO|II|CE, HLT,   0,     0,       0,0,0,     // 1111 - HLT
    };

    
    int size = sizeof(data) / sizeof(data[0]);
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if(counter == 8){
            fprintf(pf,"\n");
            counter = 0;
        }
        char binaryString[22];  
        printBinary(data[i], binaryString);  
        
        fprintf(pf, "%s%s", binaryString," ");  
        counter ++;
    }

    fclose(pf);

    return 0;
}