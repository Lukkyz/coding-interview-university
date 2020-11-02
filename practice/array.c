#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
  int size;
  int capacity;
  int *data;
} Array;

int size(Array *arrptr);
Array *new_array(int size);
int capacity(Array *arrptr);
void show(Array *arrptr);
bool is_empty(Array *arrptr);
int push(Array *arrptr, int value);
void insert(Array *arrptr, int index, int value);
int pop(Array *arrptr);
void delete (Array *arrptr, int index);
void remve(Array *arrptr, int value);
int find(Array *arrptr, int value);

int main() {
  Array *arr = new_array(10);
  return 0;
}

Array *new_array(int size) {
  Array *arr = malloc(sizeof(Array));
  if (size < 0) {
    printf("Size must be superior to 0");
    exit(EXIT_SUCCESS);
  }
  arr->size = size * 4;
  arr->capacity = size;
  arr->data = (int *)malloc(sizeof(int) * arr->capacity);
  return arr;
}

int size(Array *arrptr) { return arrptr->size; }

int capacity(Array *arrptr) { return arrptr->capacity; }

void show(Array *arrptr) {
  for (int i = 0; i < arrptr->capacity; i++) {
    printf("Index %i at address %p : %i\n", i, (arrptr->data + i),
           *(arrptr->data + i));
  }
  printf("\n");
}

bool is_empty(Array *arrptr) { return arrptr->capacity == 0; }

int at(Array *arrptr, int index) {
  if (index < 0 || index > arrptr->capacity - 1) {
    printf("Index out of range");
    exit(EXIT_FAILURE);
  }
  return *(arrptr->data + index);
}

int push(Array *arrptr, int value) {
  arrptr->data =
      (int *)realloc(arrptr->data, sizeof(int) * arrptr->capacity + 1);
  *(arrptr->data + arrptr->capacity) = value;
  arrptr->size += sizeof(int);
  arrptr->capacity++;
  return arrptr->capacity;
}

void insert(Array *arrptr, int index, int value) {
  arrptr->data =
      (int *)realloc(arrptr->data, sizeof(int) * arrptr->capacity + 1);
  void *src = (void *)(arrptr->data + index);
  void *dest = (void *)(arrptr->data + index + 1);
  size_t size = (arrptr->capacity - index - 1) * sizeof(int);
  memmove(dest, src, size);
  *(arrptr->data + index) = value;
  arrptr->size += 4;
  arrptr->capacity++;
}

int pop(Array *arrptr) {
  arrptr->data =
      (int *)realloc(arrptr->data, sizeof(int) * arrptr->capacity - 1);
  int last = *(arrptr->data + arrptr->capacity - 1);
  arrptr->data--;
  arrptr->capacity--;
  arrptr->size -= 4;
  return last;
}

void delete (Array *arrptr, int index) {
  void *src = (void *)(arrptr->data + index + 1);
  void *dest = (void *)(arrptr->data + index);
  size_t size = (arrptr->capacity - index) * sizeof(int);
  memmove(dest, src, size);
  arrptr->data =
      (int *)realloc(arrptr->data, sizeof(int) * arrptr->capacity - 1);
  arrptr->capacity--;
  arrptr->size -= 4;
}

void remve(Array *arrptr, int value) {
  for (int i = 0; i < arrptr->capacity - 1; i++) {
    if (*(arrptr->data + i) == value) {
      delete (arrptr, i);
    }
  }
}

int find(Array *arrptr, int value) {
  int index = -1;
  for (int i = 0; i < arrptr->capacity - 1; i++) {
    if (*(arrptr->data + i) == value) {
      index = i;
      break;
    }
  }
  return index;
}
