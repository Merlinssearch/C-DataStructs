// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott

#include "../include/C-DataStructs/stack.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct AllocTracker {
    Stack *allocations;
    size_t total_bytes;
    size_t peak_bytes;
    size_t alloc_count;
} AllocTracker;

// Node to store in stack
typedef struct AllocNode {
    void *ptr;
    size_t size;
} AllocNode;

#define T_MALLOC(tracker, type) ((type *)tracker_malloc(tracker, sizeof(type)))

AllocTracker *alloctracker_create() {
  AllocTracker *tracker = (AllocTracker *)malloc(sizeof(AllocTracker));
  if (!tracker)
    return NULL;
  Stack *stack = stack_create();
  if (!stack) {
    free(tracker);
    return NULL;
  }
  tracker->allocations = stack;
  tracker->total_bytes = 0;
  tracker->peak_bytes = 0;
  tracker->alloc_count = 0;
  return tracker;
}

void *tracker_malloc(AllocTracker *tracker, size_t size) {
  if (!tracker)
    return NULL;

  void *ptr = malloc(size);
  if (!ptr)
    return NULL;

  AllocNode *node = (AllocNode *)malloc(sizeof(AllocNode));
  if (!node)
    return NULL;

  tracker->alloc_count++;
  tracker->total_bytes += size;
  node->ptr = ptr;
  node->size = size;

  bool succed = stack_push(tracker->allocations, node);
  if (!succed)
    return NULL;

  if (tracker->peak_bytes < size) {
    tracker->peak_bytes = size;
  }

  return ptr;
}

// void *tracker_malloc(AllocTracker *t, size_t size) {
//   if (!t)
//     return NULL;
//
//   void *ptr = malloc(size);
//   if (!ptr)
//     return NULL;
//
//   AllocNode *node = (AllocNode *)malloc(sizeof(AllocNode));
//   if (!node) {
//     free(ptr);
//     return NULL;
//   }
//
//   node->ptr = ptr;
//   node->size = size;
//
//   stack_push(t->allocations, node);
//
//   t->total_bytes += size;
//   t->alloc_count++;
//   if (t->total_bytes > t->peak_bytes) {
//     t->peak_bytes = t->total_bytes;
//   }
//
//   return ptr;
// }
