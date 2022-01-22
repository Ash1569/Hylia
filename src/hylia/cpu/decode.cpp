#include <iostream>

// Takes the Interger provided by hFetch and isolates each operand byte.
void hDecode(uint32_t instruction, uint8_t* opCode, uint8_t* reg1, uint8_t* reg2, uint8_t* reg3, int* immediateValue) {
	*opCode 			= (instruction&0xFF000000)>>24;
	*reg1   			= (instruction&0x00FF0000)>>16;
	*reg2   			= (instruction&0x0000FF00)>>8;
	*reg3   			= (instruction&0x000000FF);
	*immediateValue   	= (instruction&0x0000FFFF);
}