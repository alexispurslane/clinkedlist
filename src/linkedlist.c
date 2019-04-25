#include "linkedlist.h"

LLNode_t *linkedlist_new_node(void *data, size_t len, LLNode_t *prev, LLNode_t *next) {
    LLNode_t *new_node = malloc((size_t)sizeof(LLNode_t));
    new_node->data = malloc(len);
    memcpy(new_node->data, data, len);
    new_node->prev_node = prev;
    new_node->next_node = next;

    return new_node;
}

LLNode_t *linkedlist_push(LLNode_t *head, void *data, size_t len) {
    LLNode_t *new_node = linkedlist_new_node(data, len, head, head->next_node);
    head->next_node = new_node;

    return new_node;
}

LLNode_t *linkedlist_remove(LLNode_t *head) {
    head->prev_node->next_node = head->next_node;
    head->next_node->prev_node = head->prev_node;

    if (head->next_node != NULL)
        return head->next_node;
    else if (head->prev_node != NULL)
        return head->prev_node;
    else
        return NULL;
}

LLNode_t *linkedlist_find_ith_from(LLNode_t *head, size_t idx) {
    for (size_t i = 0; i < idx; i++) {
        head = head->next_node;
    }
    return head;
}

void linkedlist_free(LLNode_t *head) {
    while (head != NULL) {
        LLNode_t *next = head->next_node;
        free(head->data);
        free(head);
        head = next;
    }
}
