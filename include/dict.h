#ifndef __TABLE_H
#define __TABLE_H

#include<stdbool.h>
#include<stdint.h>

#define MAX_BOUND_LIMIT 4096 

typedef struct dictionary_head_t {
    int lookup_size;  //size of lookup table
    struct node_entry ** lookup_table; //The lookup table type
} dict;

void init_table(uint32_t size);

dict * Dict(int table_size);

void * lookup_dict(dict * Dictionary, void * key);
dict * insert_into_dict(dict * Dictionary, void * key, void * value);

static inline bool check_table_bound(uint32_t size) {
    return (size > MAX_BOUND_LIMIT) ? false : true;
}

static inline bool check_empty_row(void * pointer_to_row) {
    return (pointer_to_row == 0) ? true : false;
}

static inline bool check_pointer_memory(uint32_t current_size, uint32_t table_size) {
    return (current_size < table_size) ? true : false;
}


#endif



