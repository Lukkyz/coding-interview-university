#include <iostream>
#include <stdlib.h>

extern "C" {
#include "./linkedlist/linkedlist.h"
}
class HashTable {
public:
  LinkedList list[100];
  HashTable() {
    for (int i = 0; i < 100; i++) {
      list[i].head = NULL;
      list[i].tail = NULL;
    }
  }
  int hash(int number) { return number % 100; }
  void add(int key, int value) {
    LinkedList *index = &list[hash(key)];
    push_back(index, value);
  }
  int value(int key) {
    LinkedList index = list[hash(key)];
    return index.head->value;
  }
};
int main() {
  HashTable table;
  table.add(676799222, 26);
  std::cout << table.value(676799222);
}
