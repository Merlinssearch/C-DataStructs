# Generic Singly Linked List in C

**Author:** Maxim Ott  
**License:** MIT  
**Version:** 1.0.0  
**Year:** 2025

## Performance

| Operation | Complexity |
|-----------|------------|
| push_head() | O(1) |
| push_tail() | O(1) |
| pop_head() | O(1) |
| pop_tail() | O(n) |
| get_index() | O(n) |

## API Overview

### Create/Destroy
```c
LinkedList *ll_create(void);              // O(1)
bool ll_free(LinkedList *list);           // O(n)
```

### Push/Pop
```c
bool ll_push_head(LinkedList *list, void *data);  // O(1)
bool ll_push_tail(LinkedList *list, void *data);  // O(1)
bool ll_pop_head(LinkedList *list, void **out);   // O(1)
bool ll_pop_tail(LinkedList *list, void **out);   // O(n) yea fuck my life 
```

### Access
```c
bool ll_get_value_by_index(LinkedList *list, size_t index, void **out);
bool ll_get_index_by_value(LinkedList *list, void *data, size_t *out);
```

## Ownership Rules

**Simple Rule:** You own your `malloc()` data forever. LinkedList only owns/manages Node structures.

- You `malloc()` → **You own data**
- `ll_push_*()` → **List owns Node** (points to your data)  
- `ll_free()` → **List frees all Nodes only**
- `ll_pop_*()` → **You get data pointer back** (was always yours)
- its a dynamic typ list so i couldn solve it in a another way (i have a plan on how but i am to lazy right now) 
## Quick Start

```c
LinkedList *list = ll_create();
ll_push_tail(list, malloc_data());

int *data;
ll_pop_head(list, (void**)&data);
free(data);

ll_free(list);
```

## Examples

See:
- `examples/queue.c`
- `examples/stack.c`
- `examples/test.c`

## Testing

Is coming , maybe i try testing in python
## Notes

- Generic `void*` storage
- All functions check for NULL
- Internal helpers are `static` yea maybe i forgot this by some 
- First library → Feedback welcome!ts my first library so feel free to give me some tipps xD
Maybe i will make a a dir with examples with the function for newbies like me.
Because example > docs 
Nobody understands docs or maybe i am just dumb as fuck. 

