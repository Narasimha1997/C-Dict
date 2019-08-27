#ifndef __NODE_H
#define __NODE_H

#include<stdint.h>

struct node_entry {
    uint32_t hashed_key;
    void * key;
    void * value;
    struct node_entry * next_node;
};

struct node_entry * search_list(struct node_entry * root, uint32_t hashed_key);
struct node_entry * insert_to_list(struct node_entry * root, uint32_t hashed_key, void * key, void * value);
void delete_from_list(uint32_t hashed_key);
void display(struct node_entry * root);


#endif