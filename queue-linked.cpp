#include <cassert>
#include <stdexcept>

class Node {
public:
  int value;
  Node *next;

  explicit Node(const int value, Node *next = nullptr) : value(value), next(next) {
  }
};

class QueueLinked {
  Node *head;
  Node *tail;

public:
  explicit QueueLinked() : head(nullptr), tail(nullptr) {
  }

  ~QueueLinked() {
    Node *current = head;
    while (current) {
      Node *toDelete = current;
      current = current->next;
      delete toDelete;
    }
  }

  void enqueue(const int value) {
    Node *newNode = new Node(value);

    if (head == nullptr || tail == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  int dequeue() {
    if (head == nullptr) {
      throw std::runtime_error("queue is empty!");
    }

    Node *returnNode = head;
    const int returnValue = returnNode->value;

    head = head->next;
    delete returnNode;
    if (head == nullptr) tail = nullptr;

    return returnValue;
  }
};


int main() {
  auto ql = QueueLinked();

  ql.enqueue(1);
  ql.enqueue(2);
  assert(ql.dequeue() == 1);

  ql.enqueue(3);
  assert(ql.dequeue() == 2);

  return 0;
}
