// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott

#include <cstddef>
#include <cstdlib>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct LinkedList LinkedList;

LinkedList *ll_creat(void);
bool ll_create_node(void *data, Node **out);
// Creation: `ll_create()`
// Destruction: `ll_free()`
// Insert at head: `ll_push_front()`
// Insert at tail: `ll_push()`
// Insert after a node: `ll_insert_after()`
// Remove from head: `ll_pop_front()`
// Remove from tail: `ll_pop()`
// Remove a specific node: `ll_remove_node()`
