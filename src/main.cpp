#include <iostream>
#include <fstream>
#include "hylia/hylia.h"

int isRunning = 1;

/** Registers
 * 
 * Reg 0 is PC / Program Counter
 * Reg 1 is Reserved for Flags
 */
#define REG_COUNT 15
std::int32_t Registers[REG_COUNT] = {};

// Operands
// zero out all operands since they shouldn't have any data yet
std::uint8_t opCode = 0;
std::uint8_t reg1 = 0;
std::uint8_t reg2 = 0;
std::uint8_t reg3 = 0;

int immediateValue = 0;

// 1MB of RAM
std::uint8_t Ram[1048576] = {};

void showResult() {
	for (int Reg=0; Reg < REG_COUNT; Reg++) {
		printf("r%i = #%i\n", Reg, Registers[Reg]);
	}
}

void runHylia() {
	// While running cycle through 'Fetch Decode Execute' functions  
	while(isRunning) {
		int binExec = hFetch(Ram, Registers);

		hDecode(binExec, &opCode, &reg1, &reg2, &reg3, &immediateValue);
		hExecute(&opCode, &reg1, &reg2, &reg3, &immediateValue, Ram, Registers, &isRunning);
	}
	// Output the result of all Registers on execution halts
	showResult();
}

int main() {
	// Loads the executable into RAM
	hInit(Ram);
	runHylia();
}