#include <cassert>
#include <vector>

class SelectionSort {
public:
  static void sort(std::vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
      int smallestIdx = i;
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] < arr[smallestIdx]) {
          smallestIdx = j;
        }
      }

      const int temp = arr[i];
      arr[i] = arr[smallestIdx];
      arr[smallestIdx] = temp;
    }
  }
};

int main() {
  std::vector<int> array = {5, 4, 3, 2, 1};

  SelectionSort::sort(array);

  assert(array[0] == 1);
  assert(array[1] == 2);
  assert(array[2] == 3);
  assert(array[3] == 4);
  assert(array[4] == 5);
}
