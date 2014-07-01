#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insert(struct Node **head, int value);
struct Node* pop(struct Node **head);
void clear(struct Node **head);
struct Node* contains(struct Node **head, int value);
void print_nodes(struct Node **head);

int main(int argc, char *argv[]) {
  struct Node *head = NULL;

  printf("===== insert() =====\n");
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 1);
  print_nodes(&head);

  printf("\n===== pop() =====\n");
  struct Node *ptr = pop(&head);
  if (ptr != NULL) {
    printf("ptr: %p, ptr->data: %d, ptr->next: %p\n", ptr, ptr->data, ptr->next);
  } else {
    printf("NULL");
  }

  printf("\n===== contain() =====\n");
  struct Node *con_ptr1 = contains(&head, 3);
  printf("contains(3) => ");
  if (con_ptr1 != NULL) {
    printf("con_ptr1: %p, con_ptr1->data: %d, con_ptr1->next: %p\n", con_ptr1, con_ptr1->data, con_ptr1->next);
  } else {
    printf("not found.\n");
  }
  struct Node *con_ptr2 = contains(&head, 30);
  printf("contains(30) => ");
  if (con_ptr2 != NULL) {
    printf("con_ptr2: %p, con_ptr2->data: %d, con_ptr2->next: %p\n", con_ptr2, con_ptr2->data, con_ptr2->next);
  } else {
    printf("not found.\n");
  }

  printf("\n===== clear() =====\n");
  clear(&head);
  print_nodes(&head);

  return 0;
}

void insert(struct Node **head, int value) {
  struct Node *tmp = malloc(sizeof(struct Node));
  tmp->data = value;

  if (*head == NULL) {
    tmp->next = NULL;
  } else {
    tmp->next = *head;
  }
  *head = tmp;
}

struct Node* pop(struct Node **head) {
  struct Node *tmp = *head;

  if (*head == NULL) {
    return NULL;
  } else {
    *head = tmp->next;
    return tmp;
  }
}

void clear(struct Node **head) {
  struct Node *tmp = *head;

  while (tmp != NULL) {
    tmp = tmp->next;
    free(*head);
    *head = tmp;
  }
  *head = NULL;
}

struct Node* contains(struct Node **head, int value) {
  struct Node *tmp = *head;

  while (tmp != NULL) {
    if (tmp->data == value)
      return tmp;

    tmp = tmp->next;
  }
  return NULL;
}

void print_nodes(struct Node **head) {
  struct Node *tmp = *head;

  if (tmp == NULL) {
    printf("list is empty.\n");
    return;
  }
  
  while (tmp != NULL) {
    printf("tmp->data = %d, tmp->next = %p\n", tmp->data, tmp->next);
    tmp = tmp->next;
  }
}
