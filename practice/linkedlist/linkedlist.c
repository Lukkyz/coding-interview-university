#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void push_back(struct LinkedList *list, int value) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->value = value;
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
    return;
  }
  list->tail->next = new_node;
  list->tail = list->tail->next;
}

int pop_back(struct LinkedList *list) {
  struct Node *current = list->head;
  while (current->next->next) {
    current = current->next;
  }
  int value = current->next->value;
  struct Node *pop = current->next;
  free(pop);
  current->next = NULL;
  return value;
}

int value_n_from_end(struct LinkedList *list, int index) {
  int size_list = size(list);
  struct Node *current = list->head;
  for (int i = 0; i < size_list - index - 1; i++) {
    current = current->next;
  }
  return current->value;
}

void erase(struct LinkedList *list, int index) {
  struct Node *current = list->head;
  if (index == 0) {
    list->head = list->head->next;
    free(current);
  } else {
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    struct Node *erase = current->next;
    current->next = current->next->next;
    if (!current->next) {
      list->tail = current;
    }
    free(erase);
  }
}

void show(struct LinkedList *list) {
  struct Node **current = &list->head;
  while ((*current)->next) {
    printf("%i\n", (*current)->value);
    current = &(*current)->next;
  }
  printf("%i\n", (*current)->value);
}

void insert(struct LinkedList *list, int index, int value) {
  struct Node *new_node = malloc(sizeof(struct Node));
  struct Node **current = &list->head;
  for (int i = 0; i < index - 1; i++) {
    current = &(*current)->next;
  };
  new_node->value = value;
  new_node->next = (*current)->next;
  if (new_node->next == NULL) {
    list->tail = new_node;
  }
  (*current)->next = new_node;
}

int front(struct LinkedList *list) { return list->head->value; }

int back(struct LinkedList *list) { return list->tail->value; }

int pop_front(struct LinkedList *list) {
  struct Node *next = list->head->next;
  int value = list->head->value;
  free(list->head);
  list->head = next;
  return value;
}

void push_front(struct LinkedList *list, int value) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->value = value;
  new_node->next = list->head;
  list->head = new_node;
  if (list->head->next == NULL) {
    list->tail = new_node;
  }
}

int value_at(struct LinkedList *list, int index) {
  struct Node **current = &list->head;
  for (int i = 0; i < index; ++i) {
    current = &(*current)->next;
  }
  return (*current)->value;
}

int empty(struct LinkedList *list) { return (size(list) > 0) ? 0 : 1; }

int size(struct LinkedList *list) {
  if (!(*list).head) {
    return 0;
  }
  struct Node **current = &list->head;
  int size = 1;
  while ((*current)->next) {
    size++;
    current = &(*current)->next;
  }
  return size;
}
