#ifndef T
#error you need to define T before including this header
#else

#ifndef CAT
#define _CAT(A, B) A##_##B
#define CAT(A, B) _CAT(A, B)
#endif

#include <stdbool.h>
#include <stdlib.h>

#define NODE CAT(Node, T)
#define LIST CAT(List, T)

typedef struct NODE NODE;

struct NODE {
    T value;
    NODE *next;
};


typedef struct LIST LIST;

struct LIST {
    NODE *head;
    NODE *tail;
};

#define node_new CAT(node_new, T)
#define list_new CAT(list_new, T)
#define list_push_back CAT(list_push_back, T)
#define list_push_front CAT(list_push_front, T)
#define list_pop_front CAT(list_pop_front, T)
#define list_make_empty CAT(list_make_empty, T)

NODE *node_new(T value) {
    NODE *ptr = malloc(sizeof(NODE));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

LIST list_new(void) {
    LIST list = {
        .head = NULL,
        .tail = NULL,
    };
    return list;
}

void list_push_back(LIST *self, T value) {
    NODE *node = node_new(value);
    if (self->head == NULL) {
        self->head = node;
        self->tail = node;
        return;
    }
    self->tail->next = node;
    self->tail = node;
}

void list_push_front(LIST *self, T value) {
    NODE *node = node_new(value);
    if (self->head == NULL) {
        self->head = node;
        self->tail = node;
        return;
    }
    node->next = self->head;
    self->head = node;
}

int list_pop_front(LIST *self, bool *was_empty) {
    *was_empty = false;
    if (self->head == NULL) {
        *was_empty = true;
        return 0;
    }
    NODE *old_head = self->head;
    self->head = old_head->next;
    if (self->head == NULL) {
        self->tail = NULL;
    }
    int value = old_head->value;
    free(old_head);
    return value;
}

void list_make_empty(LIST *list) {
    bool is_empty = false;
    while (!is_empty) {
        list_pop_front(list, &is_empty);
    }
}
#undef LIST
#undef NODE
#undef T
#endif
