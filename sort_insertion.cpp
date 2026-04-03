#include <cassert>
#include <iostream>
#include <vector>

class InsertionSort {
public:
  static void sort(std::vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
      for (int j = i; j > 0; j--) {
        if (arr[j] < arr[j - 1]) {
          const int temp = arr[j];
          arr[j] = arr[j - 1];
          arr[j - 1] = temp;
        } else {
          break;
        }
      }
    }
  }
};

int main() {
  std::vector<int> array = {5, 4, 3, 2, 1};
  InsertionSort::sort(array);

  assert(array[0] == 1);
  assert(array[1] == 2);
  assert(array[2] == 3);
  assert(array[3] == 4);
  assert(array[4] == 5);
}
