#include<dict.h>
#include<node.h>

#include<stdio.h>
#include<hash.h>

#include<string.h>
#include<stdlib.h>

dict * Dict(int table_size) {
    //This is a memory - time tradeoff
    //If you have a big lookup table, collisions will be less, so faster lookup
    //big lookup tables can occupy larger memory

    //We disallow use of large lookup tables, so the size of lookup is restricted to max of 4096 entries
    dict * d_pointer = (dict *)malloc(sizeof(dict));
    if(table_size > MAX_BOUND_LIMIT) {
        printf("Exceeds maximum size of 4096\n");
        return d_pointer;
    } 
    d_pointer->lookup_size = table_size;
    
    d_pointer->lookup_table = (struct node_entry **)calloc(table_size, sizeof(struct node_entry *));
    //creates a static lookup table with fixed size
    

    return d_pointer;
}

dict * insert_into_dict(dict * Dictionary, void * key, void * value) {
    if(Dictionary->lookup_table == 0) printf("Uninitialized lookup table\n");
    
    uint32_t hash = murmur3_32((const uint8_t *)key, strlen(key), 10);
    
    uint32_t mapped_hash = map_to_bounds(hash, Dictionary->lookup_size);

    Dictionary->lookup_table[mapped_hash] = insert_to_list(Dictionary->lookup_table[mapped_hash], hash, key, value);
    return Dictionary;
}

void * lookup_dict(dict * Dictionary , void * key) {
    if(Dictionary->lookup_table == 0) printf("Uninitialized lookup table\n");
    
    uint32_t hash = murmur3_32((const uint8_t *)key, strlen(key), 10);
    
    uint32_t mapped_hash = map_to_bounds(hash, Dictionary->lookup_size);

    struct node_entry * result = search_list(Dictionary->lookup_table[mapped_hash], hash);

    if(result == NULL) printf("Key Error\n");

    return result->value;
}