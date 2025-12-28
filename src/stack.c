#include "../include/C-DataStructs/linked_list.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack {
    LinkedList *list;
} Stack;

Stack *stack_create() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (!stack)
    return NULL;

  stack->list = ll_create();
  if (!stack->list) {
    free(stack);
    return NULL;
  }
  return stack;
}

bool stack_push(Stack *stack, void *data) {
  if (!stack)
    return false;
  return ll_push_head(stack->list, data);
}

bool stack_pop(Stack *stack, void **out) {
  if (!stack)
    return false;
  return ll_pop_head(stack->list, out);
}

bool stack_peek(Stack *stack, void **out) {
  if (!stack)
    return false;
  return ll_peek_head(stack->list, out);
}

bool stack_destroy(Stack *stack) {
  if (!stack)
    return false;
  ll_free(stack->list);
  free(stack);
  return true;
}

bool stack_is_empty(Stack *stack) {
  // this comment is for format
  return ll_is_empty(stack->list);
}
