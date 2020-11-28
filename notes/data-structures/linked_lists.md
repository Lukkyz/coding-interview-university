### LinkedList

Linked List

```c
struct LinkedList {
  struct Node *head;
  struct Node *tail;
}
```

Node

```c
struct Node {
  int value;
  struct Node *next;
}
```

Access O(n)  
Search O(n)  
Insert O(1)  
Delete O(1)
