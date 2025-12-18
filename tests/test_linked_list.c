// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Maxim Ott
#include "../include/C-DataStructs/linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Test counter
static int tests_run = 0;
static int tests_passed = 0;

// Color codes for output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

// Test macro
#define TEST(name)                                                             \
  void name();                                                                 \
  printf("Running: %s\n", #name);                                              \
  name();                                                                      \
  tests_run++;

#define ASSERT(condition, message)                                             \
  do {                                                                         \
    if (!(condition)) {                                                        \
      printf(RED "  ✗ FAILED: %s\n" RESET, message);                           \
      printf("    at %s:%d\n", __FILE__, __LINE__);                            \
      return;                                                                  \
    }                                                                          \
  } while (0)

#define PASS()                                                                 \
  do {                                                                         \
    printf(GREEN "  ✓ PASSED\n" RESET);                                        \
    tests_passed++;                                                            \
  } while (0)

// Helper function to create int data
int *create_int(int value) {
  int *data = malloc(sizeof(int));
  if (data)
    *data = value;
  return data;
}

// ============================================================================
// TESTS
// ============================================================================

void test_ll_create() {
  LinkedList *list = ll_creat();

  ASSERT(list != NULL, "ll_creat should not return NULL");
  ASSERT(list->head == NULL, "New list head should be NULL");
  ASSERT(list->tail == NULL, "New list tail should be NULL");
  ASSERT(list->size == 0, "New list size should be 0");

  ll_free(list);
  PASS();
}

void test_ll_create_node() {
  int *data = create_int(42);
  Node *node = NULL;

  bool success = ll_create_node(data, &node);

  ASSERT(success == true, "ll_create_node should return true");
  ASSERT(node != NULL, "Node should not be NULL");
  ASSERT(node->data == data, "Node data should match input");
  ASSERT(*(int *)node->data == 42, "Node data value should be 42");
  ASSERT(node->next == NULL, "New node next should be NULL");

  free(node->data);
  free(node);
  PASS();
}

void test_ll_create_node_null_out() {
  int *data = create_int(42);

  bool success = ll_create_node(data, NULL);

  ASSERT(success == false, "ll_create_node should return false for NULL out");

  free(data);
  PASS();
}

void test_ll_push_head_empty_list() {
  LinkedList *list = ll_creat();
  int *data = create_int(10);

  bool success = ll_push_head(list, data);

  ASSERT(success == true, "ll_push_head should return true");
  ASSERT(list->head != NULL, "Head should not be NULL");
  ASSERT(list->tail != NULL, "Tail should not be NULL");
  ASSERT(list->head == list->tail,
         "Head and tail should be same for single element");
  ASSERT(*(int *)list->head->data == 10, "Head data should be 10");
  ASSERT(list->size == 1, "Size should be 1");

  ll_free(list);
  PASS();
}

void test_ll_push_head_multiple() {
  LinkedList *list = ll_creat();

  ll_push_head(list, create_int(30));
  ll_push_head(list, create_int(20));
  ll_push_head(list, create_int(10));

  ASSERT(list->size == 3, "Size should be 3");
  ASSERT(*(int *)list->head->data == 10, "Head should be 10");
  ASSERT(*(int *)list->tail->data == 30, "Tail should be 30");

  // Check order: 10 -> 20 -> 30
  Node *current = list->head;
  ASSERT(*(int *)current->data == 10, "First element should be 10");
  current = current->next;
  ASSERT(*(int *)current->data == 20, "Second element should be 20");
  current = current->next;
  ASSERT(*(int *)current->data == 30, "Third element should be 30");
  ASSERT(current->next == NULL, "Last node next should be NULL");

  ll_free(list);
  PASS();
}

void test_ll_push_tail_empty_list() {
  LinkedList *list = ll_creat();
  int *data = create_int(10);

  bool success = ll_push_tail(list, data);

  ASSERT(success == true, "ll_push_tail should return true");
  ASSERT(list->head != NULL, "Head should not be NULL");
  ASSERT(list->tail != NULL, "Tail should not be NULL");
  ASSERT(list->head == list->tail,
         "Head and tail should be same for single element");
  ASSERT(*(int *)list->tail->data == 10, "Tail data should be 10");
  ASSERT(list->size == 1, "Size should be 1");

  ll_free(list);
  PASS();
}

void test_ll_push_tail_multiple() {
  LinkedList *list = ll_creat();

  ll_push_tail(list, create_int(10));
  ll_push_tail(list, create_int(20));
  ll_push_tail(list, create_int(30));

  ASSERT(list->size == 3, "Size should be 3");
  ASSERT(*(int *)list->head->data == 10, "Head should be 10");
  ASSERT(*(int *)list->tail->data == 30, "Tail should be 30");

  // Check order: 10 -> 20 -> 30
  Node *current = list->head;
  ASSERT(*(int *)current->data == 10, "First element should be 10");
  current = current->next;
  ASSERT(*(int *)current->data == 20, "Second element should be 20");
  current = current->next;
  ASSERT(*(int *)current->data == 30, "Third element should be 30");

  ll_free(list);
  PASS();
}

void test_ll_pop_head_single_element() {
  LinkedList *list = ll_creat();
  ll_push_head(list, create_int(42));

  void *data = NULL;
  bool success = ll_pop_head(list, &data);

  ASSERT(success == true, "ll_pop_head should return true");
  ASSERT(data != NULL, "Popped data should not be NULL");
  ASSERT(*(int *)data == 42, "Popped data should be 42");
  ASSERT(list->head == NULL, "Head should be NULL after popping last element");
  ASSERT(list->tail == NULL, "Tail should be NULL after popping last element");
  ASSERT(list->size == 0, "Size should be 0");

  free(data);
  ll_free(list);
  PASS();
}

void test_ll_pop_head_multiple() {
  LinkedList *list = ll_creat();
  ll_push_tail(list, create_int(10));
  ll_push_tail(list, create_int(20));
  ll_push_tail(list, create_int(30));

  void *data = NULL;

  // Pop first
  ll_pop_head(list, &data);
  ASSERT(*(int *)data == 10, "First pop should be 10");
  ASSERT(list->size == 2, "Size should be 2");
  ASSERT(*(int *)list->head->data == 20, "New head should be 20");
  free(data);

  // Pop second
  ll_pop_head(list, &data);
  ASSERT(*(int *)data == 20, "Second pop should be 20");
  ASSERT(list->size == 1, "Size should be 1");
  ASSERT(*(int *)list->head->data == 30, "New head should be 30");
  ASSERT(list->head == list->tail, "Head should equal tail with one element");
  free(data);

  // Pop last
  ll_pop_head(list, &data);
  ASSERT(*(int *)data == 30, "Third pop should be 30");
  ASSERT(list->size == 0, "Size should be 0");
  ASSERT(list->head == NULL, "Head should be NULL");
  ASSERT(list->tail == NULL, "Tail should be NULL");
  free(data);

  ll_free(list);
  PASS();
}

void test_ll_pop_head_empty_list() {
  LinkedList *list = ll_creat();
  void *data = NULL;

  bool success = ll_pop_head(list, &data);

  ASSERT(success == false, "ll_pop_head should return false for empty list");
  ASSERT(data == NULL, "Data should remain NULL");

  ll_free(list);
  PASS();
}

void test_ll_pop_tail_single_element() {
  LinkedList *list = ll_creat();
  ll_push_tail(list, create_int(42));

  void *data = NULL;
  bool success = ll_pop_tail(list, &data);

  ASSERT(success == true, "ll_pop_tail should return true");
  ASSERT(data != NULL, "Popped data should not be NULL");
  ASSERT(*(int *)data == 42, "Popped data should be 42");
  ASSERT(list->head == NULL, "Head should be NULL after popping last element");
  ASSERT(list->tail == NULL, "Tail should be NULL after popping last element");
  ASSERT(list->size == 0, "Size should be 0");

  free(data);
  ll_free(list);
  PASS();
}

void test_ll_pop_tail_multiple() {
  LinkedList *list = ll_creat();
  ll_push_tail(list, create_int(10));
  ll_push_tail(list, create_int(20));
  ll_push_tail(list, create_int(30));

  void *data = NULL;

  // Pop last
  ll_pop_tail(list, &data);
  ASSERT(*(int *)data == 30, "First pop should be 30");
  ASSERT(list->size == 2, "Size should be 2");
  ASSERT(*(int *)list->tail->data == 20, "New tail should be 20");
  free(data);

  // Pop second last
  ll_pop_tail(list, &data);
  ASSERT(*(int *)data == 20, "Second pop should be 20");
  ASSERT(list->size == 1, "Size should be 1");
  ASSERT(*(int *)list->tail->data == 10, "New tail should be 10");
  ASSERT(list->head == list->tail, "Head should equal tail with one element");
  free(data);

  ll_free(list);
  PASS();
}

void test_ll_pop_tail_empty_list() {
  LinkedList *list = ll_creat();
  void *data = NULL;

  bool success = ll_pop_tail(list, &data);

  ASSERT(success == false, "ll_pop_tail should return false for empty list");

  ll_free(list);
  PASS();
}

void test_ll_free_empty_list() {
  LinkedList *list = ll_creat();

  bool success = ll_free(list);

  ASSERT(success == true, "ll_free should return true for empty list");

  PASS();
}

void test_ll_free_null() {
  bool success = ll_free(NULL);

  ASSERT(success == false, "ll_free should return false for NULL");

  PASS();
}

void test_ll_free_with_elements() {
  LinkedList *list = ll_creat();
  ll_push_tail(list, create_int(10));
  ll_push_tail(list, create_int(20));
  ll_push_tail(list, create_int(30));

  bool success = ll_free(list);

  ASSERT(success == true, "ll_free should return true");
  // If valgrind shows no leaks, this test passes!

  PASS();
}

void test_mixed_operations() {
  LinkedList *list = ll_creat();
  void *data = NULL;

  // Build: 10 -> 20 -> 30
  ll_push_tail(list, create_int(20));
  ll_push_head(list, create_int(10));
  ll_push_tail(list, create_int(30));

  ASSERT(list->size == 3, "Size should be 3");

  // Pop head: 20 -> 30
  ll_pop_head(list, &data);
  ASSERT(*(int *)data == 10, "Should pop 10");
  free(data);

  // Pop tail: 20
  ll_pop_tail(list, &data);
  ASSERT(*(int *)data == 30, "Should pop 30");
  free(data);

  ASSERT(list->size == 1, "Size should be 1");
  ASSERT(*(int *)list->head->data == 20, "Only 20 should remain");

  ll_free(list);
  PASS();
}

// ============================================================================
// MAIN
// ============================================================================

int main() {
  printf("\n");
  printf("========================================\n");
  printf("  LinkedList Tests\n");
  printf("========================================\n\n");

  // ll_create tests
  TEST(test_ll_create);

  // ll_create_node tests
  TEST(test_ll_create_node);
  TEST(test_ll_create_node_null_out);

  // ll_push_head tests
  TEST(test_ll_push_head_empty_list);
  TEST(test_ll_push_head_multiple);

  // ll_push_tail tests
  TEST(test_ll_push_tail_empty_list);
  TEST(test_ll_push_tail_multiple);

  // ll_pop_head tests
  TEST(test_ll_pop_head_single_element);
  TEST(test_ll_pop_head_multiple);
  TEST(test_ll_pop_head_empty_list);

  // ll_pop_tail tests
  TEST(test_ll_pop_tail_single_element);
  TEST(test_ll_pop_tail_multiple);
  TEST(test_ll_pop_tail_empty_list);

  // ll_free tests
  TEST(test_ll_free_empty_list);
  TEST(test_ll_free_null);
  TEST(test_ll_free_with_elements);

  // Mixed operations
  TEST(test_mixed_operations);

  // Summary
  printf("\n========================================\n");
  printf("  Results: %d/%d tests passed\n", tests_passed, tests_run);
  printf("========================================\n\n");

  if (tests_passed == tests_run) {
    printf(GREEN "✓ All tests passed!\n" RESET);
    printf("\nNow run with valgrind to check for memory leaks:\n");
    printf("  valgrind --leak-check=full ./test_linked_list\n\n");
    return 0;
  } else {
    printf(RED "✗ Some tests failed!\n" RESET);
    return 1;
  }
}
