// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott

#ifndef C_DATASTRUCTS_QUEUE_H
#define C_DATASTRUCTS_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "linked_list.h"
#include <cstddef>

typedef struct Stack {
    LinkedList *list;
} Stack;

//**
// @brief
// @param list Pointer to the LinkedList.
// @param data Pointer to the data to on the stack.
// @return
//**//

bool stack_push(Stack *stack, void *data);

//**
// @brief
// @param list Pointer to the LinkedList.
// @param data Pointer to the data to on the stack.
// @return
//**//

bool stack_pop(Stack *stack, void **out);
//**
// @brief
// @param list Pointer to the LinkedList.
// @param data Pointer to the data to on the stack.
// @return
//**//

bool peek(Stack *stack, void **out);

//**
// @brief
// @param list Pointer to the LinkedList.
// @param data Pointer to the data to on the stack.
// @return
//**//

bool isEmpty(Stack *stack);

#ifdef __cplusplus
}
#endif

#endif // C_DATASTRUCTS_QUEUE_H

/**
Todos :
    Push: Adds a new element on the stack.
    Pop: Removes and returns the top element from the stack.
    Peek: Returns the top (last) element on the stack.
    isEmpty: Checks if the stack is empty.
    Size: Finds the number of elements in the stack.
**/
