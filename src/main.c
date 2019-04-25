#include <stdio.h>
#include "linkedlist.h"

int main() {
    int value1 = 1;
    LLNode_t *list = linkedlist_new_node(&value1, sizeof(int), NULL, NULL);

    LLNode_t *current = list;
    for (int i = 1; i < 100; i++) {
        int data = i + 1;
        linkedlist_push(current, &data, sizeof(int));
        current = current->next_node;
    }

    current = list;
    for (int i = 0; i < 100; i++) {
        printf("%d:\t%d\n", i, *(int *)current->data);
        current = current->next_node;
    }

    LLNode_t *item = linkedlist_find_ith_from(list, 20);
    printf("The 20th item: %d\n", *(int *)item->data);

    linkedlist_remove(item);
    free(item->data);
    free(item);

    LLNode_t *new_item = linkedlist_find_ith_from(list, 20);
    printf("The !!new!! 20th item: %d\n", *(int *)new_item->data);

    linkedlist_free(list);

    return 0;
}
