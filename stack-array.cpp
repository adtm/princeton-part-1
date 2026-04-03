#include <cassert>
#include <stdexcept>

class StackArray {
  int *values;
  int capacity;

  int currentId;

  void resizeArray(const int newCapacity) {
    int *newValues = new int[newCapacity];
    for (int i = 0; i < currentId; i++) {
      newValues[i] = values[i];
    }

    delete[] values;

    values = newValues;
    capacity = newCapacity;
  }

public:
  explicit StackArray() {
    capacity = 2;
    currentId = 0;

    values = new int[capacity];
  }

  ~StackArray() {
    delete[] values;
  }

  void push(const int value) {
    values[currentId] = value;
    currentId++;

    if (currentId == capacity) {
      resizeArray(capacity * 2);
    }
  }

  int pop() {
    if (currentId == 0) {
      throw std::runtime_error("stack is empty!");
    }

    currentId--;
    const int value = values[currentId];

    if (currentId != 0 && currentId == capacity / 4) {
      resizeArray(capacity / 2);
    }

    return value;
  }
};


int main() {
  auto sa = StackArray();

  sa.push(1);
  sa.push(2);
  sa.push(3);

  assert(sa.pop() == 3);
  assert(sa.pop() == 2);

  sa.push(4);
  assert(sa.pop() == 4);

  return 0;
}
