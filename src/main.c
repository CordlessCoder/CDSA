#include <stdio.h>
#define T int
#include "list.h"
#define T int
#include "vector.h"
#define T float
#include "vector.h"

int main(void) {
    AllocatorInstance global_alloc = AllocatorInstance_malloc_wrapper();

    {
        List_int list = list_new_int(global_alloc);
        list_push_front_int(&list, 1);
        int removed;
        if (list_pop_front_int(&list, &removed)) {
            printf("Popped %d\n", removed);
        }
        list_push_back_int(&list, 2);
        list_push_front_int(&list, 1);
        list_push_back_int(&list, 3);
        const Node_int* current = list.head;
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

    {
        Vector_int vec = vector_new_int(global_alloc);
        vector_push_back_int(&vec, 1);
        vector_push_back_int(&vec, 2);
        vector_push_back_int(&vec, 3);

        vector_insert_int(&vec, 0, -1);

        for (size_t i = 0; i < vec.len; i++) {
            int* value = vector_get_int(&vec, i);
            printf("%d\n", *value);
        }

        int removed;
        if (vector_remove_int(&vec, 2, &removed)) {
            printf("Popped %d\n", removed);
        };

        vector_free_int(&vec);
    }

    {
        Vector_float vec = vector_new_float(global_alloc);
        vector_push_back_float(&vec, 1);
        vector_push_back_float(&vec, 2);
        vector_push_back_float(&vec, 3);

        vector_insert_float(&vec, 0, -1);

        for (size_t i = 0; i < vec.len; i++) {
            float* value = vector_get_float(&vec, i);
            printf("%f\n", *value);
        }

        float removed;
        if (vector_remove_float(&vec, 2, &removed)) {
            printf("Popped %f\n", removed);
        };

        vector_free_float(&vec);
    }

    Allocator_destroy(global_alloc);
}
