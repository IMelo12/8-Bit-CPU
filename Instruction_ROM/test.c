#include <stdio.h>
#include <string.h>


// Function to return the binary representation of an integer as a string
void printBinary(int number, char* binaryString) {
    // Iterate over each bit position from the most significant to the least significant
    for (int i = 31; i >= 0; i--) {
        // Calculate the corresponding bit (0 or 1) and store it in the string
        binaryString[31 - i] = ((number >> i) & 1) + '0';
    }
    binaryString[32] = '\0'; // Null-terminate the string
}

int main() {
    int result = 0b01011 | 0b00111; // Calculate the result using bitwise OR
    char binaryString[33]; // Array to hold the binary representation plus null terminator

    // Get the binary representation of the result
    printBinary(result, binaryString);

    // Print the decimal and binary results
    printf("Decimal: %d\n", result);
    printf("Binary: %s\n", binaryString);

    return 0;
}