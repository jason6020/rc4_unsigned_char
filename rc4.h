#ifndef rc4_h
#define rc4_h

void rc4_init(const unsigned char *key_, size_t len_);
void rc4_generate(const unsigned char *in_, const size_t len_, unsigned char *out_);

#endif //rc4.h
