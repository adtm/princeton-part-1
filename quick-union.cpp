#include <cassert>
#include <iostream>
#include <stdexcept>

class QuickUnion {
  int *ids;
  int *sizes;

  int size;

  void validate_input(const int idA, const int idB) const {
    if (idA < 0 || size <= idA) {
      throw std::invalid_argument("input is out of range!");
    }

    if (idB < 0 || size <= idB) {
      throw std::invalid_argument("input is out of range!");
    }
  }

  int findParent(int id) {
    while (id != ids[id]) {
      ids[id] = ids[ids[id]];
      id = ids[id];
    }
    return id;
  }

public:
  explicit QuickUnion(const int n) {
    ids = new int[n];
    sizes = new int[n];

    for (int i = 0; i < n; i++) {
      ids[i] = i;
      sizes[i] = 1;
    }

    size = n;
  }

  ~QuickUnion() {
    delete[] ids;
    delete[] sizes;
  }

  void connect(const int fromId, const int toId) {
    validate_input(fromId, toId);

    const int toParentId = findParent(toId);
    const int fromParentId = findParent(fromId);

    if (toParentId == fromParentId) return;

    const int toParentDepth = sizes[toParentId];
    const int fromParentDepth = sizes[fromParentId];

    if (toParentDepth < fromParentDepth) {
      ids[toParentId] = fromParentId;
      sizes[fromParentId] += sizes[toParentId];
    } else {
      ids[fromParentId] = toParentId;
      sizes[toParentId] += sizes[fromParentId];
    }
  }

  bool isConnected(int idA, int idB) {
    validate_input(idA, idB);
    return findParent(idA) == findParent(idB);
  }

  void pprint() const {
    for (int i = 0; i < size; i++) {
      std::cout << "[" << ids[i] << "]";
    }
    std::cout << std::endl;
  }
};

int main() {
  auto qu = QuickUnion(10);
  qu.pprint();

  // connect multiple nodes
  // and check that internal nodes were linked
  qu.connect(0, 1);
  qu.connect(5, 6);

  // 0 was connected to 1, and 5 to 6
  // now it will be connected to 6
  qu.connect(0, 5);
  qu.pprint();

  assert(qu.isConnected(0, 5) == true);
  assert(qu.isConnected(2, 3) == false);

  return 0;
}
