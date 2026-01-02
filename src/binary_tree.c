// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott

#include <stdlib.h>
typedef struct TreeNode {
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinTree {
    TreeNode *root;
} BinTree;

BinTree *btree_create() {
  BinTree *binTree = (BinTree *)malloc(sizeof(BinTree));
  binTree->root = NULL;
  return binTree;
}
