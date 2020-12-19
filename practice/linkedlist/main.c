#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct LinkedList linkedList;
  linkedList.head = NULL;
  linkedList.tail = NULL;
  push_back(&linkedList, 300);
  push_back(&linkedList, 600);
  push_back(&linkedList, 900);
  printf("%i", linkedList.head->value);
  printf("%i", linkedList.head->next->value);
  printf("%i", linkedList.tail->value);
  return 0;
}
