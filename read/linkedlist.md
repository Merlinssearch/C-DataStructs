
# Generic Linked List Library in C

**Author:** Maxim Ott
**License:** MIT
**Year:** 2025

---

## Overview

This is a simple **generic singly linked list** implementation in C.
It supports storing arbitrary data via `void*` and provides standard operations such as push, pop, insert, remove, and access by index or value.

The library is designed to be simple, safe, and modular, hiding internal functions where possible.

---

## Data Structures

```c
typedef struct Node {
    void *data;       // Pointer to the stored data
    struct Node *next; // Pointer to the next node in the list
} Node;

typedef struct LinkedList {
    Node *head;       // First node in the list
    Node *tail;       // Last node in the list
    size_t size;      // Number of elements in the list
} LinkedList;
```

* `head` points to the first element.
* `tail` points to the last element.
* `size` tracks the number of elements in the list.

---

## Creation

```c
LinkedList *ll_create(void);
```

* Creates a new empty linked list.
* Returns `NULL` on allocation failure.

```c
static bool ll_create_node(void *data, Node **out);
```

* Internal helper to create a new node.
* Marks it `static` to hide it from the user.

---

## Memory Management

```c
bool ll_free(LinkedList *list);
```

* Frees all nodes and the list itself.
* Also frees the `data` pointer stored in each node.
* Returns `false` if `list` is `NULL`.
* **Internal use** recommended to avoid accidental double frees.

---

## Push / Pop Operations

```c
bool ll_push_tail(LinkedList *list, void *data);
bool ll_push_head(LinkedList *list, void *data);
bool ll_pop_tail(LinkedList *list, void **out);
bool ll_pop_head(LinkedList *list, void **out);
```

* `ll_push_tail` / `ll_push_head`: add an element at the **tail** or **head**.
* `ll_pop_tail` / `ll_pop_head`: remove and return the element from **tail** or **head**.
* Maintains `head`, `tail`, and `size` invariants.
* `pop_tail` is O(n) because singly linked lists do not have backward pointers.

---

## Node Manipulation

```c
static bool ll_insert_after(LinkedList *list, Node *node, void *data);
bool ll_remove_node(LinkedList *list, Node *node, void **out);
```

* `ll_insert_after`: inserts a node **after a given node** (internal use).
* `ll_remove_node`: removes a specific node and optionally returns its data.
* These functions maintain list integrity and update `head`, `tail`, and `size` accordingly.

---

## Access Functions

```c
bool ll_get_value_by_index(LinkedList *list, size_t index, void **out);
bool ll_get_index_by_value(LinkedList *list, void *data, size_t *out);
```

* `ll_get_value_by_index`: retrieves data by zero-based index.
* `ll_get_index_by_value`: finds the index of a node containing a specific data pointer.
* Only compares the pointer value, not the content it points to.

---

## Notes

* All functions check for `NULL` list pointers to avoid crashes.
* Internal helper functions are `static` to prevent misuse.
* Generic `void*` storage requires the user to manage memory of stored data carefully.
* Push/pop operations correctly update `head`, `tail`, and `size` to keep the list consistent.

---

This library is intended as a **simple, generic, and safe foundation** for singly linked list operations in C.
Its my first library so feel free to give me some tipps xD
Maybe i will make a a dir with examples with the function for newbies like me.
Because example > docs 
Nobody understands docs or maybe i am just dumb as fuck. 

