#include <cstdlib>
#include <iostream>

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, y;
  std::cin >> n >> y;
  int a = 0, b = 0, c = 0;

  for (a = n; a >= 0; a--) {
    if (10000 * a > y) {
      continue;
    }
    for (b = n - a; b >= 0; b--) {
      if (10000 * a + 5000 * b > y) {
        continue;
      }
      for (c = n - a - b; c >= 0; c--) {
        if (a + b + c != n) {
          continue;
        }
        if (10000 * a + 5000 * b + 1000 * c == y) {
          std::cout << a << ' ' << b << ' ' << c << std::endl;
          return EXIT_SUCCESS;
        }
      }
    }
  }

  std::cout << -1 << ' ' << -1 << ' ' << -1 << std::endl;
  return EXIT_SUCCESS;
}