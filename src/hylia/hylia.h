
void hInit(uint8_t[]);

void hDecode(uint32_t instruction, uint8_t* opCode, uint8_t* reg1, uint8_t* reg2, uint8_t* reg3, int* immediateValue);

void hExecute(uint8_t* opCode, uint8_t* reg1, uint8_t* reg2, uint8_t* reg3, int* immediateValue, uint8_t Ram[1024], int32_t Registers[15], int* isRunning);

uint32_t hFetch(uint8_t Ram[1024], int32_t Registers[15]);