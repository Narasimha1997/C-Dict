#ifndef __HASH_H
#define __HASH_H

//Maximum possible bound size , you can never create a map with bound greater than this
#include<stdint.h>


static inline uint32_t map_to_bounds(uint32_t hash, const unsigned int MAX_BOUND_SIZE) {
    return hash % MAX_BOUND_SIZE;
}


uint32_t murmur3_32(const uint8_t* key, int len, uint32_t seed);

#endif