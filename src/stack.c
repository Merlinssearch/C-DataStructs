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

bool peek(Stack *stack, void **out) {
  if (!stack)
    return false;
  return ll_peek_head(stack->list, out);
}

bool is_empty(Stack *stack) { return ll_is_empty(stack->list); }
