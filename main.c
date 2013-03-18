#include <stdio.h>

#include "rc4.h"

int main(int argc, char *argv[]) {
	
	unsigned char key[4] = {0x23, 0x24, 0x12, 0x34};
	unsigned char in[6] = {0x12, 0x14, 0x15, 0x17, 0x18, 0xf2};	
	unsigned char out1[6] = {0};
	unsigned char out2[6] = {0};
	int i = 0;

	for (i = 0; i < 6; i ++) {
		
		printf("%0x ", in[i]);
	}
	printf("\n");
	
	rc4_init(key, 4);
	rc4_generate(in, 6, out1);

	for (i = 0; i < 6; i ++) {
		
		printf("%0x ", out1[i]);
	}
	printf("\n");

	rc4_init(key, 4);
	rc4_generate(out1, 6, out2);

	for (i = 0; i < 6; i ++) {
		
		printf("%0x ", out2[i]);
	}
	printf("\n");

	return 0;
}
