#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* find_list_head(struct Node*);
struct Node* create(int);
struct Node* delete(struct Node*);

void free_all_registers(struct Node*)
void print_registers(struct Node*);

struct Node* append(struct Node*, struct Node*);
struct Node* prepend(struct Node*, struct Node*);

#endif
