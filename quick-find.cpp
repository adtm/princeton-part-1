#include <cassert>
#include <iostream>
#include <stdexcept>

class QuickFind {
  int *ids;
  int size;

  void validate_input(const int idA, const int idB) const {
    if (idA < 0 || size <= idA) {
      throw std::invalid_argument("input is out of range!");
    }

    if (idB < 0 || size <= idB) {
      throw std::invalid_argument("input is out of range!");
    }
  }

public:
  explicit QuickFind(const int n) {
    ids = new int[n];
    for (int i = 0; i < n; i++) {
      ids[i] = i;
    }

    size = n;
  }

  ~QuickFind() {
    delete[] ids;
  }

  void connect(const int fromId, const int toId) {
    validate_input(fromId, toId);

    const int toParentId = ids[toId];
    const int fromParentId = ids[fromId];

    if (toParentId == fromParentId) return;
    for (int i = 0; i < size; i++) {
      if (ids[i] == fromParentId) ids[i] = toParentId;
    }
  }

  bool isConnected(const int idA, const int idB) const {
    validate_input(idA, idB);
    return ids[idA] == ids[idB];
  }

  void pprint() const {
    for (int i = 0; i < size; i++) {
      std::cout << "[" << ids[i] << "]";
    }
    std::cout << std::endl;
  }
};

int main() {
  auto qf = QuickFind(10);
  qf.pprint();

  // connect multiple nodes
  // and check that internal nodes were linked
  qf.connect(0, 1);
  qf.connect(5, 6);

  // 0 was connected to 1, and 5 to 6
  // now it will be connected to 6
  qf.connect(0, 5);
  qf.pprint();

  assert(qf.isConnected(0, 5) == true);
  assert(qf.isConnected(2, 3) == false);

  return 0;
}
