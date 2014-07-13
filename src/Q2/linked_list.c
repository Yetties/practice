#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insert(struct Node **head, int value);
struct Node* pop(struct Node **head);
void clear(struct Node **head);
struct Node* contains(struct Node *head, int value);
void print_nodes(const struct Node *head);
void print_case(const char * case_type);

int main(int argc, char *argv[]) {
  struct Node *head = NULL;
  struct Node *pop_ptr = NULL;
  struct Node *contains_ptr = NULL;

  print_case("insert");
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 1);
  print_nodes(head);

  print_case("pop");
  pop_ptr = pop(&head);
  if (pop_ptr != NULL) {
    printf("&pop_ptr: %p, pop_ptr->data: %d, pop_ptr->next: %p\n", pop_ptr, pop_ptr->data, pop_ptr->next);
    free(pop_ptr);
  } else {
    printf("NULL\n");
  }

  print_case("contains");
  contains_ptr = contains(head, 3);
  if (contains_ptr != NULL) {
    printf("&contains_ptr: %p, contains_ptr: %d, contains_ptr->next: %p\n", contains_ptr, contains_ptr->data, contains_ptr->next);
  } else {
    printf("not found.\n");
  }

  print_case("clear");
  clear(&head);
  print_nodes(head);

  return 0;
}

void insert(struct Node **head, int value) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = value;

  if (!*head) {
    new_node->next = NULL;
  } else {
    new_node->next = *head;
  }
  *head = new_node;
}

struct Node* pop(struct Node **head) {
  if (!*head) {
    return NULL;
  } else {
    struct Node *pop_node = *head;

    *head = pop_node->next;

    return pop_node;
  }
}

void clear(struct Node **head) {
  struct Node *del_node = *head;

  while (del_node) {
    del_node = del_node->next;
    free(*head);
    *head = del_node;
  }
  *head = NULL;
}

struct Node* contains(struct Node *head, int value) {
  struct Node *node = head;

  while (node) {
    if (node->data == value)
      return node;

    node = node->next;
  }
  return NULL;
}

void print_nodes(const struct Node *head) {
  const struct Node *node = head;
  int i = 0;

  if (!node) {
    printf("list is empty.\n");
    return;
  }
  
  while (node) {
    printf("%d. &node = %p, node->data = %d, node->next = %p\n", ++i, node, node->data, node->next);
    node = node->next;
  }
}

void print_case(const char * case_type) {
  printf("===== %8s =====\n", case_type);
}
