#include <iostream>
#include <stdlib.h>

class KeyValue {
public:
  int key = 0;
  int value = 0;
};

class HashTable {
public:
  KeyValue list[100];
  void show() {
    for (int i = 0; i < 100; i++) {
      std::cout << i << " ";
      std::cout << list[i].value << std::endl;
    }
  }
  int hash(int k, int m) { return k % m; }
  bool exists(int key) {
    if (list[hash(key, 100)].value != 0) {
      return true;
    }
    return false;
  }
  void add(int key, int value) {
    int i = hash(key, 100);
    while (list[i].value != 0) {
      if (i == 99) {
        i = 0;
      } else {
        i++;
      }
    }
    list[i].value = value;
    list[i].key = key;
  }
  int get(int key) {
    int i = hash(key, 100);
    while (list[i].key != key) {
      if (i == 99) {
        i = 0;
      } else {
        i++;
      }
    }
    return list[i].value;
  }
  void delete_key(int key) {
    int i = 0;
    while (list[hash(key, 100) + i].key != key) {
      i++;
    }
    list[hash(key, 100) + 1].key = 0;
    list[hash(key, 100) + 1].value = 0;
  }
};
int main() {
  HashTable table;
  table.add(34187, 4);
  table.show();
}
