#include <cassert>
#include <iostream>
#include <stdexcept>

class Node {
public:
  int value;
  Node *next;

  explicit Node(const int value, Node *next = nullptr) : value(value), next(next) {
  }
};

class StackLinked {
  Node *head;

public:
  explicit StackLinked() : head(nullptr) {
  }

  ~StackLinked() {
    Node *current = head;
    while (current) {
      Node *toDelete = current;
      current = current->next;
      delete toDelete;
    }
  }

  void push(const int value) {
    Node *newNode = new Node(value);

    newNode->next = head;
    head = newNode;
  }

  int pop() {
    if (head == nullptr) {
      throw std::runtime_error("stack is empty!");
    }

    const int returnValue = head->value;
    Node *previousHead = head;

    head = head->next;
    delete previousHead;

    return returnValue;
  }

  void pprint() const {
    const Node *current = head;
    while (current) {
      std::cout << current->value << ",";
      current = current->next;
    }
    std::cout << std::endl;
  }
};


int main() {
  auto sl = StackLinked();

  sl.push(1);
  sl.push(2);
  sl.push(3);
  sl.pprint();

  assert(sl.pop() == 3);
  assert(sl.pop() == 2);
  sl.pprint();

  return 0;
}
