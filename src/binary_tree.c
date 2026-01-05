// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott
#include <stdbool.h>
#include <stdlib.h>

// Idea : Just implement Core functions ,
// then wrapper for Searchtrees etc

typedef struct TreeNode {
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinTree {
    TreeNode *root;
    size_t number_nodes;
} BinTree;

BinTree *btree_create() {
  BinTree *binTree = (BinTree *)malloc(sizeof(BinTree));
  if (!binTree)
    return NULL;
  binTree->number_nodes = 0;
  binTree->root = NULL;
  return binTree;
}

// bad name ?
// also where do we inserert ?
// and what kind of pattern do we use ???
// thats just dumb
bool btree_insert(BinTree *tree, void *data) {
  if (!tree || !data)
    return false;
  TreeNode *treeNode = (TreeNode *)malloc(sizeof(TreeNode));
  if (!treeNode)
    return false;
  treeNode->data = data;
  treeNode->left = NULL;
  treeNode->right = NULL;
  tree->number_nodes++;
  return true;
}

// void btree_search(void);
// void btree_dfs(void);
// void btree_bfs(void);
// void btree_free(void);
// void btree_destory(void);
// void btree_delete(void);
//
//
