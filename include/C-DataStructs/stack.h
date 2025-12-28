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

bool is_empty(Stack *stack);

#ifdef __cplusplus
}
#endif

#endif // C_DATASTRUCTS_STACK_H

/**
Todos :

**/
