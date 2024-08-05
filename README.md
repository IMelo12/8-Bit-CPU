# 8 Bit CPU Simulation 
This is a simulation of an 8-bit CPU using [logisim evolution](https://github.com/kevinawalsh/logisim-evolution).
## Programs
- This repo features a pseudo compiler that converts instructions into machine code for program execution 
- This repo features two sample programs 
    - 'fibonacci': which calculate Fibonacci numbers in the range of 0 - 255
    - 'increment': which counts from 0 to 255 by 1 
## Display ROM
- This CPU uses 4 seperate ROM's (ones place, tens place, hundreds place and, sign) to convert the output of an execution from binary to HEX 
## Microcode
- The microcode in this CPU uses a 23-bit ROM to decode each instructuion in the instruction set. Each of the 23 bits represents a control signal for various componets in the CPU. 
- The microcode ROM uses 8 bit addresses to decode each instruction. From righ to left, the most significant bit(bit 7) in the address represents the status of the carry flag. Bits 3-6 represent the instruction that is being executed while bits 0-2 represent the current step of the instruction

An example for the LDA instruction:
|Flags|Instruction|Step|
|-----|-----------|----|
|`0`   |`0001`|`000`|
## Instruction Set
- Each opcode consists of 8 bits where the 4 most significant bits represent the opcode and the 4 least significant bits represent the data or memory location to be accesed during an execution.
- For example: `LDA 14` -> `00011111` 

|Instruction|Opcode|Description|
|-----------|------|-----------|
|`NOP`      | `0000`  |No operation|
|`LDA x`    | `0001`  |Load the data from memory location `x` into register A|
|`ADD x`    | `0010`  |Loads the data from memory location `x` into the B register then adds the contents of the B register with the A register|
|`SUB x`    | `0011`  |Loads the data from memory location `x` into the B register then subtracts the contents of the B register from the A register|
|`STA x`    | `0100`  |Stores the data in the A register in memory location `x`|
|`LDI x`    | `0101`  |Loads `x` into the A register|
|`JMP x`    | `0110`  |program counter performs unconditional jump to `x` then continue execution|
|`OR x`     | `0111`  |Load the data from memory location `x` into the B register then performs a bitwise OR operation with register A and B|
|`NOT`      | `1000`  |Performs a bitwise NOT operation on the contents in register A|
|`INC`      | `1001`  |Increments the value in register A by 1|
|`DEC`      | `1010`  |Decrements the value in register A by 1|
|`XOR x`    | `1011`  |Load the data from memory location `x` into the B register then performs a bitwise XOR operation with register A and B|
|`AND x`    | `1100`  |Load the data from memory location `x` into the B register then performs a bitwise AND operation with register A and B|
|`OUT`      | `1101`  |Loads the value from the A register into the output register and displays on the 7-segment HEX display|
|`HLT`      | `1110`  |Stops the execution of the CPU|
|`JMC x`    | `1111`  |program counter performs conditional jump to `x` if the flags registers carry bit is set|



