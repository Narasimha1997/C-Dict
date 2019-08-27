#include<stdio.h>
#include<stdlib.h>
#include<node.h>

struct node_entry * create_node(uint32_t hashed_key, void * key, void * value) {
    struct node_entry * node = (struct node_entry *)malloc(sizeof(struct node_entry));
    node->hashed_key = hashed_key;
    node->key = key;
    node->value = value;
    node->next_node = NULL;

    return node;
}

struct node_entry * insert_to_list(struct node_entry * root, uint32_t hashed_key, void * key, void * value) {
    if(root == NULL) {
        root = create_node(hashed_key, key, value);
        return root;
    }

    struct node_entry * temp = root;
    while(temp->next_node != NULL) temp = temp->next_node;
    temp->next_node = create_node(hashed_key, key, value);
    return root;
}

//test : 
void display(struct node_entry * root) {
    struct node_entry * n = root;
    while(n != 0) {
       printf("%u , %d\n", n->hashed_key,  *(int *)n->value);
       n = n->next_node;
    }
}

struct node_entry * search_list(struct node_entry * root, uint32_t hashed_key) {
    if(root == NULL) return NULL;

    struct node_entry * temp = root;

    while(temp != NULL) {
        if(temp->hashed_key == hashed_key) return temp;
        temp = temp->next_node;
    }

    return NULL;
}

