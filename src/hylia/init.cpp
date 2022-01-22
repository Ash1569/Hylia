#include <iostream>

void hInit(uint8_t Ram[1024]) {
	// Load the file exe.bin into the 1MB Ram Buffer.
	FILE *f = fopen("exe.bin", "rb");
	if(f){
		fseek(f, 0, SEEK_END);
		size_t file_size = ftell(f);
		rewind(f);

		fread(Ram, 1, file_size, f);
		fclose(f);
	}
}