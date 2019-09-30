#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  long long g = 0;
  long long p = 0;
  for (const auto &i : s) {
    if (i == 'g') {
      ++g;
    } else {
      ++p;
    }
  }
  std::cout << (g-p) / 2;
  return 0;
}