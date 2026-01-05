#include "../include/C-DataStructs/linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  LinkedList *list = ll_create();

  int *a = malloc(sizeof(int));
  *a = 42;
  ll_push_tail(list, a);

  int *popped;
  if (ll_pop_head(list, (void **)&popped)) {
    printf("%d\n", *popped);
    free(popped);
  }

  // Cleanup
  void *data;
  while (ll_pop_head(list, &data))
    free(data);
  ll_free(list);
}
