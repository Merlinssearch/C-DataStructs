# Generic Singly Linked List in C

**Author:** Maxim Ott  
**License:** MIT  
**Version:** 1.0.0  
**Year:** 2025

A type-agnostic singly linked list in C. Stores `void*` pointers - throw whatever you want in there.

---

## Features

- Generic `void*` storage (int, struct, your mom's phone number)
- O(1) operations for head access
- Consistent `bool` error handling
- NULL-safe (all functions check, I'm not a monster)
- You own your data, list owns the structure

---

## Performance

| Operation | Complexity | Notes |
|-----------|------------|-------|
| `push_head/tail` | O(1) | Fast as fuck |
| `pop_head` | O(1) | No complaints |
| `pop_tail` | O(n) | yea fuck my life (no prev pointer) |
| `peek_*` | O(1) | Just looking |
| `get_by_index` | O(n) | Gotta walk it |
| `delete_by_index` | O(n) | Walk + delete |

---

## API Overview

### Lifecycle
```c
LinkedList *ll_create(void);              // O(1)
bool ll_free(LinkedList *list);           // O(n) - frees Nodes only!
```

### Adding
```c
bool ll_push_head(LinkedList *list, void *data);                       // O(1)
bool ll_push_tail(LinkedList *list, void *data);                       // O(1)
bool ll_insert_after(LinkedList *list, Node *node, void *data);        // O(1)
```

### Removing
```c
bool ll_pop_head(LinkedList *list, void **out);                        // O(1)
bool ll_pop_tail(LinkedList *list, void **out);                        // O(n)
bool ll_delete_by_index(LinkedList *list, size_t index);               // O(n)
```

### Inspecting
```c
bool ll_peek_head(LinkedList *list, void **out);                       // O(1)
bool ll_peek_tail(LinkedList *list, void **out);                       // O(1)
bool ll_is_empty(LinkedList *list);                                    // O(1)
```

### Searching
```c
bool ll_get_value_by_index(LinkedList *list, size_t index, void **out);         // O(n)
bool ll_get_index_by_value(LinkedList *list, void *data, size_t *out,           // O(n)
                           bool (*cmp)(const void *, const void *));
```

---

## Ownership Rules

**Golden Rule:** You `malloc()` it, you `free()` it. List only manages Node wrappers.

```c
// You create data
int *data = malloc(sizeof(int));
*data = 42;

// List wraps it in a Node
ll_push_head(list, data);  // List owns Node, YOU own data

// You get it back
int *retrieved;
ll_pop_head(list, (void**)&retrieved);

// YOU free it
free(retrieved);

// List frees Nodes only
ll_free(list);
```

### ⚠️ Memory Leak Example
```c
// ❌ BAD: Lost pointer!
ll_push_head(list, malloc(sizeof(int)));
ll_free(list);  // ← malloc'd data leaked!

// ✅ GOOD: Free all data first
void *data;
while (ll_pop_head(list, &data)) {
    free(data);
}
ll_free(list);
```

**Why?** It's generic - could be malloc'd, stack, or literal. You decide lifetime.
But i will add an AllocTracker so u can just call the function at the end of the Code and it will free
everythink <3 

---

## Quick Start

```c
#include "C-DataStructs/linked_list.h"

int main() {
    LinkedList *list = ll_create();
    
    int *a = malloc(sizeof(int));
    *a = 42;
    ll_push_tail(list, a);
    
    int *popped;
    if (ll_pop_head(list, (void**)&popped)) {
        printf("%d\n", *popped);
        free(popped);
    }
    
    // Cleanup
    void *data;
    while (ll_pop_head(list, &data)) free(data);
    ll_free(list);
}
```

---

## Custom Types Example

```c
typedef struct { char name[64]; int age; } Person;

bool person_cmp(const void *a, const void *b) {
    return strcmp(((Person*)a)->name, ((Person*)b)->name) == 0;
}

// Usage
Person *p = malloc(sizeof(Person));
strcpy(p->name, "Alice");
ll_push_tail(list, p);

Person search = {"Alice", 0};
size_t index;
if (ll_get_index_by_value(list, &search, &index, person_cmp)) {
    printf("Found at %zu\n", index);
}
```

---

## Error Handling

All functions return `bool` (`ll_create` returns `NULL` on error).

```c
if (!ll_push_head(list, data)) {
    fprintf(stderr, "Push failed\n");
}

// Or just YOLO it
ll_push_head(list, data);  // What could go wrong?
```

---

## Examples

- `examples/example_stack.c` - Stack wrapper
- `examples/example_tree.c` - Tree implementation
- `tests/test_linked_list.c` - Tests (coming soon™)

---

## Building

```bash
make           # Build library
make test      # Run tests (TODO lol)
make clean     # Clean up
```

---

## Notes

- `ll_create_node()` is public but you probably shouldn't use it
- First library I wrote, feedback welcome
- Examples > docs (nobody reads docs anyway, or maybe I'm just dumb as fuck)

---

## TODO

- [ ] Write tests (maybe in Python because C tests are pain)
- [ ] Add `ll_reverse()` and `ll_sort()`
- [ ] Optional free callback for auto-cleanup
- [ ] AllocTracker integration

---

## License

MIT - Do whatever, just don't sue me if it breaks.
