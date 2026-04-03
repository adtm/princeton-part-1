#include <cassert>
#include <stdexcept>

class QueueArray {
  int *values;
  int capacity;

  int head;
  int tail;

  void resizeArray(int newCapacity) {
    int *newValues = new int[newCapacity];
    for (int i = head; i < tail; i++) {
      newValues[i - head] = values[i];
    }

    delete[] values;

    values = newValues;
    capacity = newCapacity;

    tail = tail - head;
    head = 0;
  }

public:
  explicit QueueArray() {
    capacity = 2;
    values = new int[capacity];

    head = tail = 0;
  }

  ~QueueArray() {
    delete[] values;
  }

  void enqueue(const int value) {
    values[tail] = value;
    tail++;

    if (tail == capacity) {
      resizeArray(2 * capacity);
    }
  }

  int dequeue() {
    if (tail - head == 0) {
      throw std::runtime_error("queue is empty!");
    }

    const int value = values[head];
    head++;

    const int newSize = tail - head;
    if (newSize != 0 && newSize == capacity / 4) {
      resizeArray(capacity / 2);
    }

    return value;
  }
};

int main() {
  auto qa = QueueArray();

  qa.enqueue(1);
  qa.enqueue(2);
  assert(qa.dequeue() == 1);

  qa.enqueue(3);
  assert(qa.dequeue() == 2);

  return 0;
}
