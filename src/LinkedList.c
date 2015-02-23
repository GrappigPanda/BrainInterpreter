#include <stdlib.h>
#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node* find_list_head(struct Node *current) {
        struct Node *head = current;

        while(head->prev != NULL) {
                head = head->prev;
        }

        return head;
}

struct Node *create(int value) {
        struct Node *tmp = malloc(2 * sizeof(struct Node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        
        return tmp;
}

struct Node* delete(struct Node *ToDelete) {
        return NULL;
}

void free_all_registers(struct Node *current) {
        struct Node *head = find_list_head(current);
        while(head->next != NULL) {
                head = head->next;
                free(head->prev);
                head->prev = NULL;
        }
        free(head);
}

struct Node *append(struct Node *fst, struct Node *sec) {
        struct Node *tmp = create(0);
        tmp->next = fst->next;

        fst->next = sec;
        sec->prev = fst;
        sec->next = tmp->next;

        return sec;
}

void print_registers(struct Node *current) {
        struct Node *head = find_list_head(current);
        int count = 0;

        while(head->next != NULL) {
                printf("%d:%d\n", count, head->value);
                head = head->next;
        }
}

struct Node* prepend(struct Node *fst, struct Node *sec) {
        struct Node *tmp = create(0);
        tmp->next = fst->next;
        tmp->prev = fst->prev;


        fst->prev = sec;
        sec->next = fst;
        sec->prev = tmp->prev;

        return sec;
}
