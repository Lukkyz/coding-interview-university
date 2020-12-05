#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next;
};

class Queue {
public:
  Node *head = NULL;
  Node *tail = NULL;
};

void enqueue(Queue *qe, int value);
bool empty(Queue *qe);
void dequeue(Queue *qe);

int main() {
  Queue qe;
  enqueue(&qe, 7);
  enqueue(&qe, 6);
  enqueue(&qe, 5);
  cout << qe.head->value << endl;
  dequeue(&qe);
  cout << qe.head->value << endl;
  dequeue(&qe);
  cout << qe.head->value << endl;
  return 0;
}

void dequeue(Queue *qe) {
  Node *first = qe->head;
  if (qe->head->next) {
    qe->head = qe->head->next;
  } else {
    qe->head = NULL;
  }
}

void enqueue(Queue *qe, int val) {
  Node *new_node = new Node();
  new_node->value = val;
  if (!qe->head) {
    qe->head = new_node;
  }
  if (!qe->tail) {
    qe->tail = new_node;
  } else {
    qe->tail->next = new_node;
    qe->tail = new_node;
  }
}

bool empty(Queue *qe) { return !qe->head; }
