#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insert(struct Node **head, int value);
int pop(struct Node **head);
void clear(struct Node **head);
int contains(const struct Node *head, int value);
void print_nodes(const struct Node *head);
void print_case(const char * case_type);

int main(int argc, char *argv[]) {
  struct Node *head = NULL;

  print_case("insert");
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 1);
  print_nodes(head);

  print_case("pop");
  printf("pop: %d\n", pop(&head));

  print_case("contains");
  printf("contains(3):%d, contains(30):%d\n", contains(head, 3), contains(head, 30));

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

int pop(struct Node **head) {
  if (!*head) {
    return 0;
  } else {
    struct Node *pop_node = *head;
    int pop_data;

    pop_data = pop_node->data;
    *head = pop_node->next;
    free(pop_node);

    return pop_data;
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

int contains(const struct Node *head, int value) {
  const struct Node *node = head;

  while (node) {
    if (node->data == value)
      return node->data;

    node = node->next;
  }
  return 0;
}

void print_nodes(const struct Node *head) {
  const struct Node *node = head;

  if (!node) {
    printf("list is empty.\n");
    return;
  }
  
  while (node) {
    printf("node->data = %d, node->next = %p\n", node->data, node->next);
    node = node->next;
  }
}

void print_case(const char * case_type) {
  printf("===== %8s =====\n", case_type);
}
