#include "../include/C-DataStructs/linked_list.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue {
    LinkedList *list;
} Queue;

Queue *queue_create() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (!queue)
    return NULL;

  queue->list = ll_create();
  if (!queue->list) {
    free(queue);
    return NULL;
  }

  return queue;
}

bool queue_destroy(Queue *queue) {
  if (!queue)
    return false;
  ll_free(queue->list);
  free(queue);
  return true;
}

bool queue_enqueue(Queue *queue, void *data) {
  if (!queue || !data)
    return false;
  return ll_push_tail(queue->list, data);
}
bool queue_dequeue(Queue *queue, void **out) {
  if (!queue || !out)
    return false;
  return ll_pop_head(queue->list, out);
}

bool queue_peek(Queue *queue, void **out) {
  if (!queue || !out)
    return false;
  return ll_peek_head(queue->list, out);
}

bool queue_is_empty(const Queue *queue) { return ll_is_empty(queue->list); }

size_t queue_size(const Queue *queue) { return queue->list->size; }
