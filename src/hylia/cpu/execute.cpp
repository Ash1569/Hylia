#include <iostream>

// Executes the operands provided by hDecode.
void hExecute(uint8_t* opCode, uint8_t* reg1, uint8_t* reg2, uint8_t* reg3, int* immediateValue, uint8_t Ram[1024], int32_t Registers[15], int* isRunning) {
	switch(*opCode) {
		// Halt
		case 0:
			printf("Halt!\n");
			*isRunning = 0;
			break;
		// Add Register
		case 1:
			printf("ADD r%i, r%i, r%i\n", *reg1, *reg2, *reg3);
			Registers[*reg3] = Registers[*reg1] + Registers[*reg2];
			break;
		// Subtract Register
		case 2:
			printf("SUB r%i, r%i, r%i\n", *reg1, *reg2, *reg3);
			Registers[*reg3] = Registers[*reg1] - Registers[*reg2];
			break;
		// Load Immediate
		case 3:
			printf("LOADI #%i, r%i\n", *immediateValue, *reg1);
			Registers[*reg1] = *immediateValue;
			break;
        // Load memory from address
        case 4:
        	printf("LOADA @%i r%i\n", *reg2, *reg1);
        	Registers[*reg1] =  (uint32_t)Ram[*reg2 + 3]<<24;
        	Registers[*reg1] += (uint32_t)Ram[*reg2 + 2]<<16;
        	Registers[*reg1] += (uint32_t)Ram[*reg2 + 1]<<8;
        	Registers[*reg1] += (uint32_t)Ram[*reg2];
        	break;
        // Copy register to register
        case 5:
        	printf("MOVR r%i r%i\n", *reg1, *reg2);
        	Registers[*reg2] = Registers[*reg1];
        	break;
        // Copy to ram
        case 6:
			printf("MOVA r%i @%i\n", *reg1, Ram[*reg2]);
			Ram[*reg2 + 0] = (Registers[*reg1]&0xFF000000)>>24;
			Ram[*reg2 + 1] = (Registers[*reg1]&0x00FF0000)>>16;
			Ram[*reg2 + 2] = (Registers[*reg1]&0x0000FF00)>>8;
			Ram[*reg2 + 3] = (Registers[*reg1]&0x000000FF);
			break;
        // Jump greater
        case 7:
			printf("JMPG #%i #%i @%i\n", Registers[*reg2] ,Registers[*reg3], Registers[*reg1]);
			if (Registers[*reg2] > Registers[*reg3])
			{
				Registers[0] = Registers[*reg1];
			}
			break;
        // Jump equal
        case 8:
			printf("JMPE #%i #%i @%i\n", Registers[*reg2] ,Registers[*reg3], Registers[*reg1]);
			if (Registers[*reg2] = Registers[*reg3])
			{
				Registers[0] = Registers[*reg1];
			}
			break;
        // Jump not equal
        case 9:
			printf("JMPNE #%i #%i @%i\n", Registers[*reg2] ,Registers[*reg3], Registers[*reg1]);
			if (Registers[*reg2] != Registers[*reg3])
			{
				Registers[0] = Registers[*reg1];
			}
			break;

	// ADDED AS OF 13/11/2021 5:24PM AWST
		
		// Jump not equal
        case 10:
			printf("JMP @%i\n", Registers[*reg1]);
				Registers[0] = Registers[*reg1];
			break;

		// Jump not zero
        case 11:
			printf("JMPNZ #%i @%i\n", Registers[*reg2], Registers[*reg1]);
			if (Registers[*reg2] != 0)
			{
				Registers[0] = Registers[*reg1];
			}
			break;

		// Jump equal zero
        case 12:
			printf("JMPEZ #%i @%i\n", Registers[*reg2], Registers[*reg1]);
			if (Registers[*reg2] == 0)
			{
				Registers[0] = Registers[*reg1];
			}
			break;

		// Jump greater then zero
        case 13:
			printf("JMPGZ #%i @%i\n", Registers[*reg2], Registers[*reg1]);
			if (Registers[*reg2] > 0)
			{
				Registers[0] = Registers[*reg1];
			}
			break;

		// Jump less then zero
        case 14:
			printf("JMPLZ #%i @%i\n", Registers[*reg2], Registers[*reg1]);
			if (Registers[*reg2] < 0)
			{
				Registers[0] = Registers[*reg1];
			}
			break;



        // Undefined
        default:
			printf("Undefined opCode!\n");
			break;
	}
}