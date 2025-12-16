Linked List - Key Points for C Implementation

1. **Core Structure**

* `Node`: contains `data` and pointer to `next` node.
* `LinkedList`: contains `head`, `tail`, and optionally `size`.

2. **Memory Management**

* Always `malloc` nodes; check for `NULL` return.
* Free nodes individually when deleting or freeing the list.
* Keep `tail` and `head` pointers consistent after insertions/deletions.

3. **Basic Operations**

* Creation: `ll_create()`
* Destruction: `ll_free()`
* Insert at head: `ll_push_front()`
* Insert at tail: `ll_push()`
* Insert after a node: `ll_insert_after()`
* Remove from head: `ll_pop_front()`
* Remove from tail: `ll_pop()`
* Remove a specific node: `ll_remove_node()`

4. **Search / Access**

* `ll_search()` returns first node matching data.
* `ll_get_at()` accesses node by index.
* `ll_index_of()` optional: returns first occurrence index.

5. **Utility Functions**

* `ll_is_empty()` checks if list is empty.
* `ll_length()` returns size (O(1) if stored, O(n) otherwise).
* `ll_print()` for debugging / example output.

6. **Optional Advanced Operations**

* `ll_reverse()` in-place reverse.
* `ll_clone()` deep copy of list.
* `ll_sort()` sorting of list elements.

7. **Best Practices**

* Keep API clean: do not rely on internal state like `current`.
* Always update `head`, `tail`, and `size` consistently.
* Use modular approach: separate header (`.h`) and source (`.c`) files.
* Include license headers for each file if making a library.

8. **Learning Approach**

* Start with core head/tail operations.
* Add search and remove functions.
* Extend with index-based and advanced operations after basics are stable.
* Test each function thoroughly with small examples before combining.

9. **C Language Notes**

* Use `stdbool.h` for boolean operations.
* Include proper `#include` headers (`stdio.h`, `stdlib.h`).
* Use `size_t` for size/index counters.
* Always handle `NULL` pointers gracefully.
