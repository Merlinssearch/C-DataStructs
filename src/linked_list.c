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
LinkedList *ll_create() {
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

// Free all Node of LinkedList and the LinkedList it self
bool ll_free(LinkedList *list) {
  if (list == NULL)
    return false;

  Node *currentNode;
  Node *nextNode;

  while (list->head != NULL) {
    nextNode = currentNode->next;
    free(currentNode->data);
    free(currentNode);
    currentNode = nextNode;
  }

  free(list);
  return true;
}

// Gives back the last element
// then deletes it in O(n)
bool ll_pop_tail(LinkedList *list, void **out) {
  Node *currentNode;

  if (list == NULL || list->tail == NULL || list->head == NULL)
    return false;

  *out = list->tail->data;

  if (list->head == list->tail) {
    free(list->tail);
    list->size = 0;
    list->tail = NULL;
    list->head = NULL;
    return true;
  }
  currentNode = list->head;
  while (currentNode->next != list->tail) {
    currentNode = currentNode->next;
  }
  free(list->tail);
  list->tail = currentNode;
  list->tail->next = NULL;
  list->size--;
  return true;
}

bool ll_push_tail(LinkedList *list, void *data) {
  if (list == NULL)
    return false;
  Node *newNode = NULL;
  bool succeed = ll_create_node(data, &newNode);
  if (!succeed)
    return false;
  if (list->head == NULL && list->tail == NULL) {
    list->head = newNode;
    list->tail = newNode;
    return true;
  }
  list->tail->next = newNode;
  list->tail = newNode;
  list->tail->next = NULL;
  list->size++;
  return true;
}
bool ll_pop_head(LinkedList *list, void **out) {
  if (list == NULL || list->head == NULL)
    return false;
  *out = list->head->data;
  Node *oldHead = list->head;
  list->head = list->head->next;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  free(oldHead);
  list->size--;
  return true;
}
bool ll_push_head(LinkedList *list, void *data) {
  if (list == NULL)
    return false;
  Node *newNode = NULL;
  bool succeed = ll_create_node(data, &newNode);
  if (!succeed)
    return false;
  if (list->head == NULL && list->tail == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    newNode->next = list->head;
    list->head = newNode;
  }
  list->size++;
  return true;
}

bool ll_insert_after(LinkedList *list, Node *node, void *data) {
  if (list == NULL || node == NULL)
    return false;
  Node *newNode = NULL;
  Node *tempNode = NULL;
  bool succeed = ll_create_node(data, &newNode);
  if (!succeed)
    return false;
  if (list->head == NULL && list->tail == NULL) {
    list->head = newNode;
    list->tail = newNode;
    return true;
  }
  if (node == list->tail) {
    list->tail = newNode;
  }
  tempNode = node->next;
  node->next = newNode;
  newNode->next = tempNode;
  list->size++;
  return true;
}

bool ll_remove_node(LinkedList *list, Node *node, void **out) { return true; }

bool ll_get_value_by_index(LinkedList *list, size_t index, void **out) {
  return true;
}

bool ll_get_index_by_value(LinkedList *list, void *data, size_t *out) {
  return true;
}
