C Naming & Header Conventions
=============================

1. Types / Structs / Enums
--------------------------
- Use UpperCamelCase (PascalCase)
- Examples:
  typedef struct LinkedList LinkedList;
  typedef struct Node Node;
  typedef enum Color Color;

2. Functions
------------
- Use lower_snake_case
- Examples:
  LinkedList *ll_create(void);
  bool ll_push(LinkedList *list, void *data);
  void ll_free(LinkedList *list, void (*destroy)(void *));

3. Struct Members / Variables
-----------------------------
- Use lower_snake_case
- Examples:
  struct LinkedList {
      Node *head;
      Node *tail;
      size_t size;
  };

4. Header Files (.h)
--------------------
- Only declarations (function prototypes, typedefs, macros)
- No function definitions
- Use include guards:
  #ifndef LINKED_LIST_H
  #define LINKED_LIST_H
  // declarations
  #endif

5. Source Files (.c)
--------------------
- Contain function definitions and internal structs
- Keep internal structs (e.g., Node) private if users don’t need them
- Include the header for type consistency

6. Error Handling
-----------------
- Creation functions: return pointer (NULL = failure)
- Mutating functions: return bool or status code
- Avoid crashing; let the caller handle errors

7. Memory Management
--------------------
- Always free heap allocations (malloc)
- If struct contains dynamically allocated fields, free them first
- Encapsulate node allocation in private helper functions
