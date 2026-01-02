# AllocTracker Idea
Ownership is hard so this should solve the problem . 
I have to write it anyway in every programm i use this libary as a helper 
so just implement it in the Linkelist or the other C-DataStructs
PS : i will write an extra lib for this type of stuff. 
## Core Concept

```c
tracker_int(t, 42)      // malloc() + track() + return
tracker_free_all(t)     // free EVERYTHING
```

## Usage

```c
AllocTracker *t = tracker_create();

ll_push_head(list, tracker_int(t, 42));
ll_push_head(list, tracker_str(t, "hello"));

tracker_free_all(t);  // ZERO leaks!
```

## Why This Works

- Zero boilerplate
- Type-safe helpers
- One-line cleanup

**Future:** `utils/alloc_tracker.h` as part of C-DataStructs library

## Additional Features to Consider

### Debug Mode
```c
tracker_create_debug(true);  // Logs every alloc/free
tracker_print_stats(t);      // Shows: allocated, freed, leaked
```

### Tagging & Groups
```c
tracker_malloc_tagged(t, size, "user_data");
tracker_free_group(t, "user_data");  // Free only tagged items
```

### Size Tracking
```c
size_t total = tracker_total_bytes(t);
size_t peak = tracker_peak_usage(t);
```

### Safety Features
```c
// Detect double-free attempts
// Guard bytes to detect buffer overruns
// Optional: stack traces for each allocation (debug builds)
```

### Integration with Existing Code
```c
#define malloc(s) tracker_malloc(global_tracker, s)
#define free(p) tracker_free(global_tracker, p)
// Drop-in replacement for legacy code
```

### Scoped Allocations
```c
TRACKER_SCOPE(t) {
    // All allocations auto-freed at scope exit
    char *temp = tracker_str(t, "temporary");
}  // temp freed here automatically
```

### Performance Considerations
- Use hash table for O(1) pointer lookup
- Optional: thread-local trackers for multi-threaded apps
- Compile-time flag to disable tracking in production builds
