#include <stdbool.h>

typedef struct Stack {
    LinkedList *list;
} Stack;

bool stack_push(Stack *stack, void *data) { return true; }

bool stack_pop(Stack *stack) { return true; }

bool stack_pop_peak(Stack *stack, void **out) { return true; }

bool peek(Stack *stack, void **out) { return true; }

bool isEmpty(Stack *stack) { return true; }
