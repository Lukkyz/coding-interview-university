#include <iostream>
#include <math.h>
#include <stdlib.h>

int binary_search(int *array, int size, int value) {
  int min = 0;
  int max = 9;
  int index = round(size / 2);
  while (abs(min - max) != 1) {
    if (array[index] == value)
      break;
    if (array[index] > value) {
      max = index;
    } else if (array[index] < value) {
      min = index;
    }
    index = round((min + max) / 2);
  }
  return index;
}

int recursive_binary(int array[], int min, int max, int x) {
  if (max >= 1) {
    int index = min + (max - 1) / 2;
    if (array[index] == x) {
      return index;
    }
    if (array[index] > x) {
      return recursive_binary(array, min, index - 1, x);
    }
    return recursive_binary(array, index + 1, max, x);
  }
  return -1;
}

int main() {
  int arr[] = {2, 4, 8, 9, 10, 11, 12, 45, 48, 49};
  int result = recursive_binary(arr, 0, 9, 48);
  std::cout << result;
}
