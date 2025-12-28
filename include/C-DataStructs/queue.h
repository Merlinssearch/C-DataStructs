// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott

#ifndef C_DATASTRUCTS_QUEUE_H
#define C_DATASTRUCTS_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "linked_list.h"
#include <cstddef>

typedef struct Queue {
    LinkedList *list;
} Queue;

typedef struct Queue Queue;

Queue *queue_create(void);
bool queue_destroy(Queue *queue);
bool queue_enqueue(Queue *queue, void *data);
bool queue_dequeue(Queue *queue, void **out);
bool queue_peek(Queue *queue, void **out);
bool queue_is_empty(Queue *queue);
size_t queue_size(Queue *queue);

#ifdef __cplusplus
}
#endif

#endif // C_DATASTRUCTS_QUEUE_H

/**
Todos :

**/
