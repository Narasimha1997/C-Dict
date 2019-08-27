#include<stdio.h>
#include<stdint.h>
#include<string.h>

#include<hash.h>
/*
  https://en.wikipedia.org/wiki/MurmurHash
  Murmur is a fast hash function that takes few nano-seconds to compute hash
  MurMur is not a cryptographic hash function, so it is used only for lookup
*/

uint32_t murmur3_32(const uint8_t* key, int len, uint32_t seed)
{
	uint32_t h = seed;
	if (len > 3) {
		size_t i = len >> 2;
		do {
			uint32_t k;
			memcpy(&k, key, sizeof(uint32_t));
			key += sizeof(uint32_t);
			k *= 0xcc9e2d51;
			k = (k << 15) | (k >> 17);
			k *= 0x1b873593;
			h ^= k;
			h = (h << 13) | (h >> 19);
			h = h * 5 + 0xe6546b64;
		} while (--i);
	}
	if (len & 3) {
		size_t i = len & 3;
		uint32_t k = 0;
		do {
			k <<= 8;
			k |= key[i - 1];
		} while (--i);
		k *= 0xcc9e2d51;
		k = (k << 15) | (k >> 17);
		k *= 0x1b873593;
		h ^= k;
	}
	h ^= len;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return h;
}

