#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  for (unsigned i = 0; i < s.size() - 1; ++i) {
    if (s[i] == s[i + 1]) {
      std::cout << i + 1 << " " << i + 2;
      return 0;
    }
  }
  for (unsigned i = 0; i < s.size() - 2; ++i) {
    if (s[i] == s[i + 2]) {
      std::cout << i + 1 << " " << i + 3;
      return 0;
    }
  }
  std::cout << -1 << " " << -1;
  return 0;
}