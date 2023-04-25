#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//simple linked list that stores integers only (for now)
typedef struct t_node {
    int value;
    struct t_node *next;
} t_node;

#define NODE_SIZE sizeof(t_node)

//create node and return pointer to it or NULL if val is not an integer/empty/malloc fails
t_node* create_node(int value) {

    t_node* new_node = malloc(NODE_SIZE);

    if (new_node == NULL) {
        return NULL;
    }

    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

//insert node at the start of the list
t_node* insert_node_at_head(t_node** head, t_node* new_node) {
    if (head == NULL || new_node == NULL) {
        return NULL;
    }

    new_node->next = *head;
    *head = new_node;

    return new_node;
}

//insert node at the end of the list
t_node* insert_node_at_tail(t_node** head, t_node* new_node) {
    if (head == NULL || new_node == NULL) {
        return NULL;
    }

    t_node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;

    return new_node;
}

t_node* insert_after(t_node* target, t_node* new_node) {
    if (target == NULL || new_node == NULL) {
        return NULL;
    }

    new_node->next = target->next;
    target->next = new_node;

    return new_node;

}

t_node* find_node_by_value(t_node* head, int value) {
    t_node *tmp = head;

    while (tmp != NULL) {
        if(tmp->value == value) return tmp;
        tmp = tmp->next;
    }

    //unsafe ?
    return NULL;
}

t_node* insert_before(t_node* target, t_node* new_node, t_node* head) {

    t_node *tmp = head;

    while (tmp != NULL) {
        if(tmp->next == target) {
            tmp->next = new_node;
            new_node->next = target;
        }
        tmp = tmp->next;
    }

    //unsafe ?
    return NULL;

}

void traverse(t_node* head) {
    t_node* tmp = head;

    while(tmp->next != NULL) {
        printf("%d --->", tmp->value);
        tmp = tmp->next;
    }

    return;
}

void remove_node(t_node** head, t_node* target) {
    if (head == NULL || target == NULL) {
        return;
    }

    t_node* current = *head;

    if (current == target) {
        *head = current->next;
        free(current);
        return;
    }

    while (current->next != target) {
        current = current->next;
    }

    current->next = target->next;
    free(target);
}

int main (void) {

    t_node* head = create_node(1);
    t_node* node1 = create_node(4);
    head->next = node1;
    t_node* node2 = create_node(2);
    node1->next = node2;
    t_node* node3 = create_node(32);
    node2->next = node3;
    t_node* node4 = create_node(12);
    node3->next = node4;

    t_node* found_node = find_node_by_value(head,12);

    printf("%d node", found_node->value);
    traverse(head);
    remove_node(&head, node3);

    traverse(head);

    return 0;
};