#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;
  for (int i = 0; i < int(s.length()) - 1; ++i) {
    if (s[i] == s[i + 1]) {
      std::cout << i + 1 << ' ' << i + 2 << std::endl;
      return 0;
    }
  }
  for (int i = 0; i < int(s.length()) - 2; ++i) {
    if (s[i] == s[i + 2]) {
      std::cout << i + 1 << ' ' << i + 3 << std::endl;
      return 0;
    }
  }
  std::cout << "-1 -1" << std::endl;
  return 0;
}