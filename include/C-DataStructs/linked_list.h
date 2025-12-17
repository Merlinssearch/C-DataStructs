// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

LinkedList *ll_creat(void);
bool ll_create_node(void *data, Node **out);
bool ll_free(LinkedList *list);

bool ll_pop_tail(LinkedList *list, void **out_data);
bool ll_push_tail(void *data);

bool ll_pop_head(LinkedList *list, void **out_data);
bool ll_push_head(void *data);

// Insert at head: `ll_push_head()`
// Insert at tail: `ll_push_tail()`
// Insert after a node: `ll_insert_after()` after what ? index , node , i dont
// know Remove from head: `ll_pop_head()` Remove from tail: `ll_pop_tail()`
// Remove a specific node: `ll_remove_node()`
// Get the Value by Index of the Pointer : ll_get_value_by_index
// Get Index of Value : ll_get_index_by_value
