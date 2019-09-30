#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> ary(17);
  unsigned long N;
  int len = 0;
  std::cin >> N;
  for (int i = 0; i < 17; i++) {
    ary[i] = (int) (N % 10);
    N /= 10;
    len++;
    if (N == 0) break;
  }

  int max = 0;
  for (int i = 0; i < len; i++) {
    int sum = 0;
    for (int j = 0; j < len; j++) {
      sum += ary[j];
    }
    max = std::max(max, sum);
    if (ary[i] != 9) {
      ary[i] = 9;
      for (int j = i + 1; j < len; j++) {
        if (ary[j] != 0) {
          ary[j]--;
          break;
        } else ary[j] = 9;
      }
    }
  }

  std::cout << max;

  return 0;
}