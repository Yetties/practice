#include <stdio.h>
#include <stdlib.h>

void insert(int);
struct node* pop(void);
void clear(void);
struct node* contains(int);
void print_nodes(void);

struct node *g_head;

struct node{
  int data;
  struct node *next;
};

int main(int argc, char *argv[]) {
  return 0;
}

void insert(int value) {
  struct node *tmp = malloc(sizeof(struct node));
  tmp->data = value;

  if (g_head == NULL) {
    tmp->next = NULL;
  } else {
    tmp->next = g_head;
  }
  g_head = tmp;
}

struct node* pop(void) {
  struct node *tmp = g_head;

  if (g_head == NULL) {
    return NULL;
  } else {
	g_head = g_head->next;
	return tmp;
  }
}

void clear(void) {
  struct node *tmp = g_head;

  while (tmp != NULL) {
    tmp = g_head->next;
	free(g_head);
	g_head = tmp;
  }
  g_head = NULL;
}

struct node* contains(int value) {
  struct node *tmp = g_head;

  while (tmp != NULL) {
    if (tmp->data == value) {
      return tmp;
	}
	tmp = tmp->next;
  }
  return NULL;
}

void print_nodes(void) {
  struct node *tmp = g_head;

  while (tmp != NULL) {
    printf("tmp->data = %d, tmp->next = %p\n", tmp->data, tmp->next);
    tmp = tmp->next;
  }
}
