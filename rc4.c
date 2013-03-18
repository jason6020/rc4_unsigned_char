#include <string.h>
#include <stdlib.h>

#include "rc4.h"

static unsigned char sbox[256];

void rc4_init(const unsigned char *key_, size_t len_) {
	
	int i = 0;
	int j = 0;
	
	for (i = 0; i < 256; i ++) sbox[i] = i;

	for (i = 0; i < 256; i ++) {
		
		j = (j + sbox[i] + key_[i%len_]) % 256;
		
		int tmp = sbox[i];
		sbox[i] = sbox[j];
		sbox[j] = tmp;
	}
}

void rc4_generate(const unsigned char *in_, const size_t len_, unsigned char *out_) {
	
	int x = 0;
	int y = 0;
	int i = 0;
	int k = 0;

	for (i = 0; i < len_; i ++) {
		
		x = (x + 1) % 256;
		y = (y + sbox[x]) % 256;

		int tmp = sbox[x];
		sbox[x] = sbox[y];
		sbox[y] = tmp;

		k = in_[i] ^ sbox[ (sbox[x] + sbox[y]) % 256 ];
		out_[i] = k;
	}
}
