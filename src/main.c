#include <stdio.h>
#define T int
#include "list.h"

int main(void) {
    List_int list = list_new_int();
    list_push_back_int(&list, 1);
    list_push_back_int(&list, 2);
    list_push_back_int(&list, 3);
    Node_int *current = list.head;
    printf("[");
    while (current) {
        printf("%d", current->value);
        current = current->next;
        if (current) {
            printf(", ");
        }
    }
    printf("]\n");
    list_make_empty_int(&list);
}
