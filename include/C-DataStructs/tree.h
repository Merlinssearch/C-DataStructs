// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott

#include <stddef.h>

typedef struct TreeNode {
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BTree {
    TreeNode *root;
    size_t number_nodes;
} BTree;

BTree *btree_create(void);
void btree_insert(void);
void btree_search(void);
void btree_dfs(void);
void btree_bfs(void);
void btree_free(void);
void btree_destory(void);
void btree_delete(void);

// Basic Function for Trees
// Create – create a tree in the data structure.
// Insert − Inserts data in a tree.
// Search − Searches specific data in a tree to check whether it is present or
// not. Traversal: Depth-First-Search Traversal Breadth-First-Search Traversal
