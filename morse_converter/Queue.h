#ifndef QUEUE_H
#define QUEUE_H

struct Node {
  char data;
  Node* next;

  Node(char data) : data(data), next(nullptr) {}
};

class CharQueue {
private:
  Node* head;
  Node* tail;
public:
  CharQueue() : head(nullptr), tail(nullptr) {}
  ~CharQueue() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(char c) {
    Node* newNode = new Node(c);
    if (isEmpty()) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  char pop() {
    if (isEmpty()) {
      return '\0';
    }

    char c = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
      tail = nullptr;
    }

    return c;
  }

  bool isEmpty() {
    return head == nullptr;
  }
};

#endif
