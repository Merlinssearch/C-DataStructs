#include "../include/C-DataStructs/linked_list.h"
#include <stdbool.h>
// #include <stdio.h>
#include <stdlib.h>

int main() {
  // Create list
  LinkedList *list = ll_creat();
  for (int i = 0; i < 10; i++) {
    int *ptrInt = (int *)malloc(sizeof(int));
    *ptrInt = i;
    Node *ptrNode = NULL;
    ll_create_node(&ptrInt, &ptrNode);
  }

  return 0;
}
