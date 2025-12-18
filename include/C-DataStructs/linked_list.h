// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

LinkedList *ll_create(void);

bool ll_create_node(void *data, Node **out);

/**
 * @brief Frees all nodes of a LinkedList and the LinkedList itself.
 *
 * @param list Pointer to the LinkedList to free. Can be NULL.
 * @return true if the list was successfully freed, false if the list was NULL.
 *
 * @note This function also frees the `data` pointer inside each node.
 */
bool ll_free(LinkedList *list);

/**
 * @brief Removes the last element (tail) from the list and returns its data.
 *
 * @param list Pointer to the LinkedList.
 * @param out Pointer to a void* that will receive the data of the removed node.
 * @return true if an element was removed, false if the list was empty or NULL.
 *
 * @note This operation runs in O(n) time because singly linked lists do not
 *       have a pointer to the previous node.
 */
bool ll_pop_tail(LinkedList *list, void **out);

/**
 * @brief Appends a new element to the end (tail) of the list.
 *
 * @param list Pointer to the LinkedList.
 * @param data Pointer to the data to store in the new node.
 * @return true if the node was successfully created and added, false otherwise.
 *
 * @note If the list is empty, both head and tail are set to the new node.
 */
bool ll_push_tail(LinkedList *list, void *data);

/**
 * @brief Removes the first element (head) from the list and returns its data.
 *
 * @param list Pointer to the LinkedList.
 * @param out Pointer to a void* that will receive the data of the removed node.
 * @return true if an element was removed, false if the list was empty or NULL.
 *
 * @note If the list becomes empty after this operation, tail is set to NULL.
 */
bool ll_pop_head(LinkedList *list, void **out);

/**
 * @brief Inserts a new element at the beginning (head) of the list.
 *
 * @param list Pointer to the LinkedList.
 * @param data Pointer to the data to store in the new node.
 * @return true if the node was successfully created and added, false otherwise.
 *
 * @note If the list is empty, both head and tail are set to the new node.
 */

bool ll_push_head(LinkedList *list, void **out);

// Insert at head: `ll_push_head()`
// Insert after a node: `ll_insert_after()` after what ? index , node , i dont
// know Remove a specific node: `ll_remove_node()` with index or value ? Get the
// Value by Index of the Pointer : ll_get_value_by_index Get Index of Value :
// ll_get_index_by_value
