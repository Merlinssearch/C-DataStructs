// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott

#ifndef C_DATASTRUCTS_STACK_H
#define C_DATASTRUCTS_STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "linked_list.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct Stack {
    LinkedList *list;
} Stack;

/**
 * @brief Create a new Stack.
 * @return Pointer to a newly allocated Stack, or NULL on allocation failure.
 */
Stack *stack_create(void);

/**
 * @brief Push data onto the top of the stack.
 * @param stack Pointer to the Stack.
 * @param data Pointer to the data to push.
 * @return true if successful, false if stack is NULL or allocation fails.
 */
bool stack_push(Stack *stack, void *data);

/**
 * @brief Pop data from the top of the stack.
 * @param stack Pointer to the Stack.
 * @param out Pointer to store the popped data.
 * @return true if successful, false if stack is NULL, empty, or out is NULL.
 */
bool stack_pop(Stack *stack, void **out);

/**
 * @brief Peek at the top element of the stack without removing it.
 * @param stack Pointer to the Stack.
 * @param out Pointer to store the top element.
 * @return true if successful, false if stack is NULL, empty, or out is NULL.
 */
bool stack_peek(Stack *stack, void **out);

/**
 * @brief Check if the stack is empty.
 * @param stack Pointer to the Stack.
 * @return true if the stack is empty or stack is NULL, false otherwise.
 */
bool stack_is_empty(Stack *stack);

/**
 * @brief Destroy the stack and free all memory.
 * @param stack Pointer to the Stack to destroy.
 * @return true if successfully destroyed, false if stack is NULL.
 */
bool stack_destroy(Stack *stack);

#ifdef __cplusplus
}
#endif

#endif // C_DATASTRUCTS_STACK_H
