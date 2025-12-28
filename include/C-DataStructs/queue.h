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

/**
 * @brief Create a new Queue.
 * @return Pointer to a newly allocated Queue, or NULL on allocation failure.
 */
Queue *queue_create(void);

/**
 * @brief Destroy a Queue and free all its memory.
 * @param queue Pointer to the Queue to destroy.
 * @return true if successfully destroyed, false if queue is NULL.
 */
bool queue_destroy(Queue *queue);

/**
 * @brief Enqueue data at the end of the queue (FIFO).
 * @param queue Pointer to the Queue.
 * @param data Pointer to the data to enqueue.
 * @return true if successful, false if queue is NULL or allocation fails.
 */
bool queue_enqueue(Queue *queue, void *data);

/**
 * @brief Dequeue data from the front of the queue (FIFO).
 * @param queue Pointer to the Queue.
 * @param out Pointer to store the dequeued data.
 * @return true if successful, false if queue is NULL, empty, or out is NULL.
 */
bool queue_dequeue(Queue *queue, void **out);

/**
 * @brief Peek at the front element of the queue without removing it.
 * @param queue Pointer to the Queue.
 * @param out Pointer to store the front element.
 * @return true if successful, false if queue is NULL, empty, or out is NULL.
 */
bool queue_peek(Queue *queue, void **out);

/**
 * @brief Check if the queue is empty.
 * @param queue Pointer to the Queue.
 * @return true if the queue is empty or queue is NULL, false otherwise.
 */
bool queue_is_empty(Queue *queue);

/**
 * @brief Get the number of elements in the queue.
 * @param queue Pointer to the Queue.
 * @return Number of elements, 0 if queue is NULL.
 */
size_t queue_size(Queue *queue);

#ifdef __cplusplus
}
#endif

#endif // C_DATASTRUCTS_QUEUE_H

/**
Todos :

**/
