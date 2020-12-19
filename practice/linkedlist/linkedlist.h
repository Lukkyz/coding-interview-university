struct Node {
  int value;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
};

int size(struct LinkedList *list);
int empty(struct LinkedList *list);
int value_at(struct LinkedList *list, int index);
void push_front(struct LinkedList *list, int value);
int pop_front(struct LinkedList *list);
int front(struct LinkedList *list);
int back(struct LinkedList *list);
void insert(struct LinkedList *list, int index, int value);
void show(struct LinkedList *list);
void erase(struct LinkedList *list, int index);
int value_n_from_end(struct LinkedList *list, int index);
void push_back(struct LinkedList *list, int value);
int pop_back(struct LinkedList *list);
