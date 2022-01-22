#include <iostream>

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