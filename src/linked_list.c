// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott
#include <stdbool.h>
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

// Always Check if this return NULL;
LinkedList *ll_creat() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Destruction: `ll_free()`
// Insert at head: `ll_push_front()`
// Insert at tail: `ll_push()`
// Insert after a node: `ll_insert_after()`
// Remove from head: `ll_pop_front()`
// Remove from tail: `ll_pop()`
// Remove a specific node: `ll_remove_node()`
