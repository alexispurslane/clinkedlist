#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LLNode {
    struct LLNode *next_node;
    struct LLNode *prev_node;
    void *data;
} LLNode_t;

LLNode_t *linkedlist_new_node(void *data, LLNode_t *prev, LLNode_t *next);

LLNode_t *linkedlist_push(LLNode_t *head, void *data);
LLNode_t *linkedlist_remove(LLNode_t *head);
LLNode_t *linkedlist_find_ith_from(LLNode_t *head, size_t idx);

void linkedlist_free(LLNode_t *head);
