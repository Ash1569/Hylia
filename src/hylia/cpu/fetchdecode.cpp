#include <iostream>

// Takes the Interger provided by hFetch and isolates each operand byte.
void hDecode(uint32_t instruction, uint8_t* opCode, uint8_t* reg1, uint8_t* reg2, uint8_t* reg3, int* immediateValue) {
	*opCode 			= (instruction&0xFF000000)>>24;
	*reg1   			= (instruction&0x00FF0000)>>16;
	*reg2   			= (instruction&0x0000FF00)>>8;
	*reg3   			= (instruction&0x000000FF);
	*immediateValue   	= (instruction&0x0000FFFF);
}

// Gets then next instruction from the RAM Buffer and returns for decoding
uint32_t hFetch(uint8_t Ram[1024], int32_t Registers[15]) {
	// Encodes as LE/Little Endian
	uint32_t instruction = 0;
	instruction =  (uint32_t)Ram[Registers[0]*4 + 3]<<24;
	instruction += (uint32_t)Ram[Registers[0]*4 + 2]<<16;
	instruction += (uint32_t)Ram[Registers[0]*4 + 1]<<8;
	instruction += (uint32_t)Ram[Registers[0]*4];
	Registers[0]++;
	
	return instruction;
}