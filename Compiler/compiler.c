/*
    pseudo compiler to generate RAM instruction for several programs
*/


#include <stdio.h>
#include <stdlib.h>


#define LDA 0b0001
#define STA 0b0100
#define ADD 0b0010
#define OUT 0b1101
#define HLT 0b1110
#define NOP 0b0000
#define INC 0b1001
#define JMP 0b0110
#define JMC 0b1111

void hex(char* string, int numb){
    sprintf(string,"%X",numb);
}

int main(){
    FILE *pf = fopen("fibonacci.txt","w");
    FILE *pf_inc = fopen("Increment.txt","w");
    
    int code_inc[] = {
        (LDA << 4)|0b1111, 
        (INC << 4),
        (JMC << 4)|0b0110, 
        (OUT << 4), 
        (STA << 4)|0b1111, 
        (JMP << 4)|0b0000, 
        (HLT << 4), 
        0, 
        0,
        0, 
        0, 
        0, 
        0, 
        0, 
        0,  
        0};

    int code_fib[] = {
        (LDA << 4)|0b1111, 
        (ADD << 4)|0b1110,
        (JMC << 4)|0b1010, 
        (OUT << 4), 
        (STA << 4)|0b1101,
        (LDA << 4)|0b1111,
        (STA << 4)|0b1110,
        (LDA << 4)|0b1101,
        (STA << 4)|0b1111,
        (JMP << 4)|0b0000,
        (HLT << 4),
        0,
        0,
        0,
        0,
        0b0001
    };

    int size = sizeof(code_fib)/sizeof(code_fib[0]);
    int size_inc = sizeof(code_inc)/sizeof(code_inc[0]);

    char *program_inc = (char*)calloc(16,sizeof(size));
    char *program_fib = (char*)calloc(16,sizeof(size_inc));

    for(int i = 0; i<size; i++){
        hex(program_fib, code_fib[i]);
        fprintf(pf,"%s ",program_fib);
    }

    for(int i = 0; i<size_inc; i++){
        hex(program_inc,code_inc[i]);
        fprintf(pf_inc,"%s ",program_inc);
    }
    
    fclose(pf);
    fclose(pf_inc);
    free(program_fib);
    free(program_inc);
    
    return 0;
}