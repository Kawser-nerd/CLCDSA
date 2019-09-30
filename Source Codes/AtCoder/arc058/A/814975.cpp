#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  int n, k, d;
  bool is_safe[10] = {};
  std::cin >> n >> k;
  std::fill(is_safe, is_safe + 10, true);
  for (int ki = 0 ; ki < k; ++ki) {
    std::cin >> d;
    is_safe[d] = false;
  }
  while (true) {
    int r = n;
    while (r > 0) {
      if (not is_safe[r % 10]) {
        goto fail;
      }
      r /= 10;
    }
    std::cout << n << std::endl;
    return 0;
fail:
    ++n;
  }
}