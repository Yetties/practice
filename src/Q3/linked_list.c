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
void reverse_list(struct Node **head);
void insert_sorted(struct Node **head, int value);

int main(int argc, char *argv[]) {
  struct Node *head = NULL;

  print_case("insert");
  insert_sorted(&head, 3);
  insert_sorted(&head, 1);
  insert_sorted(&head, 2);
  insert_sorted(&head, 4);
  insert_sorted(&head, 1);
  print_nodes(head);

  print_case("reverse");
  reverse_list(&head);
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

void reverse_list(struct Node **head) {
  if (!head)
    return;

  struct Node *node = *head;
  struct Node *pre_node = NULL;
  while (node) {
    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->data = node->data;
    new_node->next = pre_node;

    pre_node = new_node;
    node = node->next;
  }

  node = *head;
  while (node) {
    free(node);
    node = node->next;
  }
  *head = pre_node;
}

void insert_sorted(struct Node **head, int value) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = value;

  if (!*head) {
    new_node->next = NULL;
    *head = new_node;
    return;
  }

  struct Node *node = *head;
  while (node) {
    /* at beginning of list */
    if (value < node->data && node == *head) {
      new_node->next = node;
      *head = new_node;
      return;
    }

    /* at middle or end of list */
    if (node->next) {
      if (value >= node->data && value < node->next->data) {
        new_node->next = node->next;
        node->next = new_node;
        return;
      }
    } else {
      new_node->next = node->next;
      node->next = new_node;
      return;
    }

    node = node->next;
  }
}
