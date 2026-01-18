// ReSharper disable once CppMissingIncludeGuard
#ifndef T
#error you need to define T before including this header
#else

#ifndef CAT
#define CAT_(A, B) A##_##B
#define CAT(A, B) CAT_(A, B)
#endif

#include <stdbool.h>
#include <stdlib.h>

#define NODE CAT(Node, T)
#define LIST CAT(List, T)

typedef struct NODE NODE;

struct NODE
{
    T value;
    NODE* next;
};


typedef struct LIST LIST;

struct LIST
{
    NODE* head;
    NODE* tail;
};

#define node_new CAT(node_new, T)
#define list_new CAT(list_new, T)
#define list_push_back CAT(list_push_back, T)
#define list_push_front CAT(list_push_front, T)
#define list_pop_front CAT(list_pop_front, T)
#define list_make_empty CAT(list_make_empty, T)

static NODE*node_new(const T value)
{
    NODE* ptr = malloc(sizeof(NODE));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

static LIST list_new(void)
{
    const LIST list = {
        .head = NULL,
        .tail = NULL,
    };
    return list;
}

static void list_push_back(LIST* self, const T value)
{
    NODE* node = node_new(value);
    if (self->head == NULL)
    {
        self->head = node;
        self->tail = node;
        return;
    }
    self->tail->next = node;
    self->tail = node;
}

static void list_push_front(LIST* self, T value)
{
    NODE* node = node_new(value);
    if (self->head == NULL)
    {
        self->head = node;
        self->tail = node;
        return;
    }
    node->next = self->head;
    self->head = node;
}

static int list_pop_front(LIST* self, bool* was_empty)
{
    *was_empty = false;
    if (self->head == NULL)
    {
        *was_empty = true;
        return 0;
    }
    NODE* old_head = self->head;
    self->head = old_head->next;
    if (self->head == NULL)
    {
        self->tail = NULL;
    }
    const int value = old_head->value;
    free(old_head);
    return value;
}

static void list_make_empty(LIST* list)
{
    bool is_empty = false;
    while (!is_empty)
    {
        list_pop_front(list, &is_empty);
    }
}
#undef LIST
#undef NODE
#undef T
#endif
