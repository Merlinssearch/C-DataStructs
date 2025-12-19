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
/**
 * @brief Creates a LinkedList and set :
 *   Node *head = NULL;
 *   Node *tail = NULL;
 *   size_t size = 0;
 *   Important : You Pass Owner ships from your Data to LinkedList
 *   This is a single pointer LinkedList
 **/
LinkedList *ll_create(void);

// making it static hides it for the User

bool ll_create_node(void *data, Node **out);

/**
 * @brief Frees all nodes of a LinkedList and the LinkedList itself.
 *
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
 * @ownership : ll_free() --> call this function to free all memory
 * NEVER call if u free Memory
 * @param list Pointer to the LinkedList.
 * @param data Pointer to the data to store in the new node.
 * @return true if the node was successfully created and added, false otherwise.
 *
 * @note If the list is empty, both head and tail are set to the new node.
 */
bool ll_push_tail(LinkedList *list, void *data);

/**
 * @brief Removes the first element (head) from the list and returns its data.
 * @param list Pointer to the LinkedList.
 * @param out Pointer to a void* that will receive the data of the removed node.
 * @return true if an element was removed, false if the list was empty or NULL.
 *
 * @note If the list becomes empty after this operation, tail is set to NULL.
 */
bool ll_pop_head(LinkedList *list, void **out);

/**
 * @brief Inserts a new element at the beginning (head) of the list.
 * @ownership : ll_free() --> call this function to free all memory
 * NEVER call if u free Memory
 * @param list Pointer to the LinkedList.
 * @param data Pointer to the data to store in the new node.
 * @return true if the node was successfully created and added, false otherwise.
 *
 * @note If the list is empty, both head and tail are set to the new node.
 */

bool ll_push_head(LinkedList *list, void *data);

/**
 * @brief Inserts a new element at the beginning (head) of the list.
 *
 * @param list Pointer to the LinkedList.
 * @param data Pointer to the data to store in the new node.
 * @return true if the node was successfully created and added, false otherwise.
 *
 * @note If the list is empty, both head and tail are set to the new node.
 */
bool ll_push_head(LinkedList *list, void *data);

/**
 * @brief Inserts a new element after a given node in the list.
 * (for internal use)
 *
 * @param list Pointer to the LinkedList.
 * @param node Pointer to the node after which the new node will be inserted.
 *             Must be non-NULL and belong to the list.
 * @param data Pointer to the data to store in the new node.
 * @return true if the node was successfully created and added, false otherwise.
 *
 * @note If `node` is the tail, this function behaves like `ll_push_tail()`.
 */
bool ll_insert_after(LinkedList *list, Node *node, void *data);

/**
 * @brief Removes a specific node from the list.
 *
 * @param list Pointer to the LinkedList.
 * @param node Pointer to the node to remove. Must belong to the list.
 * @param out Optional pointer to store the node's data before freeing. Can be
 * NULL.
 * @return true if the node was removed, false if `node` was NULL or not in the
 * list.
 */
// bool ll_remove_node(LinkedList *list, Node *node, void **out);

/**
 * @brief Retrieves the data of a node by its index.
 *
 * @param list Pointer to the LinkedList.
 * @param index Zero-based index of the node.
 * @param out Pointer to store the data of the node at the given index.
 * @return true if the index was valid, false otherwise.
 */
bool ll_get_value_by_index(LinkedList *list, size_t index, void **out);

/**
 * @brief Finds the index of the first node containing the given data pointer.
 *
 * @param list Pointer to the LinkedList.
 * @param data Pointer to the data to search for.
 * @param out Pointer to store the zero-based index of the node. Ignored if not
 * found.
 * @return true if a node with matching data was found, false otherwise.
 *
 * @note Compares data pointers, not the content they point to.
 */

bool ll_get_index_by_value(LinkedList *list, void *data, size_t *out);
