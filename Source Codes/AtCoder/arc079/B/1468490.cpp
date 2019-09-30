#include <iostream>

int main() {
  uint64_t K;
  std::cin >> K;
  uint64_t q = K / 50ull + 1;
  uint64_t r = 50ull - K % 50ull;
  if (K % 50ull == 0) {
    r = 0;
    --q;
  }
  if (q == 0) {
    if (r == 0) {
      std::cout << 2 << std::endl;
      std::cout << 1 << " " << 1 << std::endl;
    } else if (r == 1) {
      std::cout << 2 << std::endl;
      std::cout << 0 << " " << 2 << std::endl;
    } else {
      std::cout << r << std::endl;
      for (unsigned i = 0; i < r; ++i) {
        std::cout << i + 1 << " ";
      }
    }
  } else {
    std::cout << 50 << std::endl;
    for (unsigned i = 0; i < 50; ++i) {
      std::cout << (i < r ? q - 1 : q) << " ";
      ++q;
    }
  }
  std::cout << std::endl;
  return 0;
}