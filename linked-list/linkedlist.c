#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//simple linked list that stores integers only (for now)
typedef struct t_node {
    int data;
    struct t_node *next;
} t_node;

#define NODE_SIZE sizeof(t_node)

//create node and return pointer to it or NULL if val is not an integer/empty/malloc fails
t_node* create_node(int val) {

    t_node* new_node = malloc(NODE_SIZE);

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = val;
    new_node->next = NULL;

    return new_node;
}

int main () {

    t_node* head = create_node(1);

    return 0;
};