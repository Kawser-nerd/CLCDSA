#include <iostream>
#include <string>
#include <vector>

int main() {
  int a, b;
  std::cin >> a >> b;
  char base = '#';
  char paint = '.';
  int cnt = a - 1;
  std::cout << 100 << " " << 100 << std::endl;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (cnt <= 0 || i == 50 || i % 2 == 1 || j % 2 == 1) {
        std::cout << base;
      } else {
        std::cout << paint;
        --cnt;
      }
    }
    std::cout << std::endl;
    if (i == 50) {
      std::swap(base, paint);
      cnt = b - 1;
    }
  }
}