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

// Always Check if this return NULL;
LinkedList *ll_creat() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (list == NULL)
    return NULL;
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

bool ll_create_node(void *data, Node **out) {
  Node *newNode;
  if (out == NULL)
    return false;
  newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
    return false;
  newNode->data = data;
  newNode->next = NULL;
  *out = newNode;
  return true;
}

bool ll_free(LinkedList *list) {
  if (list == NULL)
    return false;
  Node *tempNode;
  while (list->head != NULL) {
    tempNode = list->head->next;
    list->head = tempNode;
    free(tempNode->data);
    free(tempNode);
  }
  free(list);
  return true;
}

bool ll_pop_tail(LinkedList *list, void **out) {
  Node *tempNode;
  Node *prevNode;
  if (list == NULL || list->tail == NULL)
    return false;
  *out = list->tail->data;
  free(list->tail);
  tempNode = list->head;
  while (tempNode->next != NULL) {
    prevNode = tempNode;
    tempNode = tempNode->next;
  }
  list->tail = prevNode;
  return true;
}

bool ll_push_tail(void *data) { return true; }
bool ll_pop_head(LinkedList *list, void **out_data) { return true; }
bool ll_push_head(void *data) { return true; }
