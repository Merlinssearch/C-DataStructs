#include "../include/C-DataStructs/linked_list.h"
#include <stdbool.h>
typedef struct Stack {
    LinkedList *list;
} Stack;

bool stack_push(Stack *stack, void *data) {
  if (!stack->list || !data)
    return false;
  return ll_push_head(stack->list, data);
}

bool stack_pop(Stack *stack, void **out) {
  if (!stack->list || !out)
    return false;
  return ll_pop_head(stack->list, out);
}

bool peek(Stack *stack, void **out) {
  if (!stack->list || !out)
    return false;
  return ll_peek_head(stack->list, out);
}

bool isEmpty(Stack *stack) { return ll_is_empty(stack->list); }
