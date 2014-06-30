#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void insert(struct node **head, int value);
struct node* pop(struct node **head);
void clear(struct node **head);
struct node* contains(struct node **head, int value);
void print_nodes(struct node **head);

int main(int argc, char *argv[]) {
  struct node *head = NULL;

  printf("===== insert() =====\n");
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 1);
  print_nodes(&head);

  printf("\n===== pop() =====\n");
  struct node *ptr = pop(&head);
  if (ptr != NULL) {
    printf("ptr: %p, ptr->data: %d, ptr->next: %p\n", ptr, ptr->data, ptr->next);
  } else {
    printf("NULL");
  }

  printf("\n===== contain() =====\n");
  struct node *con_ptr1 = contains(&head, 3);
  printf("contains(3) => ");
  if (con_ptr1 != NULL) {
    printf("con_ptr1: %p, con_ptr1->data: %d, con_ptr1->next: %p\n", con_ptr1, con_ptr1->data, con_ptr1->next);
  } else {
    printf("not found.\n");
  }
  struct node *con_ptr2 = contains(&head, 30);
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

void insert(struct node **head, int value) {
  struct node *tmp = malloc(sizeof(struct node));
  tmp->data = value;

  if (head == NULL) {
    tmp->next = NULL;
  } else {
    tmp->next = *head;
  }
  *head = tmp;
}

struct node* pop(struct node **head) {
  struct node *tmp = *head;

  if (head == NULL) {
    return NULL;
  } else {
    *head = tmp->next;
    return tmp;
  }
}

void clear(struct node **head) {
  struct node *tmp = *head;

  while (tmp != NULL) {
    tmp = tmp->next;
    free(*head);
    *head = tmp;
  }
  *head = NULL;
}

struct node* contains(struct node **head, int value) {
  struct node *tmp = *head;

  while (tmp != NULL) {
    if (tmp->data == value)
      return tmp;

    tmp = tmp->next;
  }
  return NULL;
}

void print_nodes(struct node **head) {
  struct node *tmp = *head;

  if (tmp == NULL) {
    printf("list is empty.\n");
    return;
  }
  
  while (tmp != NULL) {
    printf("tmp->data = %d, tmp->next = %p\n", tmp->data, tmp->next);
    tmp = tmp->next;
  }
}
