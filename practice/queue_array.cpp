#include <iostream>

using namespace std;

class Queue {
public:
  int last = 0;
  int first = 0;
  int size;
  int *array;
  Queue(int sze) {
    size = sze;
    array = (int *)malloc(sizeof(int) * size);
  }
  bool empty(Queue *qe) { return qe->first == qe->last; }
  bool full(Queue *qe) {
    if (qe->last - qe->first == qe->size) {
      return true;
    }
    return false;
  }
  void enqueue(Queue *qe, int value) {
    if (qe->last == qe->size) {
      cout << "Error list full" << endl;
      return;
    }
    qe->array[qe->last] = value;
    qe->last++;
  }

  int dequeue(Queue *qe) {
    int popped = qe->array[qe->first];
    qe->array[qe->first] = 0;
    qe->first++;
    return popped;
  }
};

int main() {
  Queue *qe = new Queue(5);
  qe->enqueue(qe, 12);
  qe->enqueue(qe, 12);
  qe->enqueue(qe, 12);
  qe->enqueue(qe, 12);
  qe->enqueue(qe, 16);
  for (int i = 0; i < qe->size; i++) {
    cout << qe->array[i] << endl;
  }
}
