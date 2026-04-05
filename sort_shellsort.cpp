#include <cassert>
#include <iostream>
#include <vector>

class ShellSort {
public:
  static void sort(std::vector<int> &arr) {
    int h = 1;
    while (3 * h + 1 < arr.size()) {
      h = 3 * h + 1;
    }

    while (h >= 1) {
      for (int i = h; i < arr.size(); i++) {
        for (int j = i; j >= h; j -= h) {
          if (arr[j] < arr[j - h]) {
            const int temp = arr[j];
            arr[j] = arr[j - h];
            arr[j - h] = temp;
          } else {
            break;
          }
        }
      }

      h = h / 3;
    }
  }
};


int main() {
  std::vector<int> array = {5, 4, 3, 2, 1};

  ShellSort::sort(array);

  assert(array[0] == 1);
  assert(array[1] == 2);
  assert(array[2] == 3);
  assert(array[3] == 4);
  assert(array[4] == 5);
}
