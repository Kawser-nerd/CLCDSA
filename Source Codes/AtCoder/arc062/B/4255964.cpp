#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  int res = 0;
  for (size_t i = 0; i < s.length(); ++i) {
    if (i % 2 == 0) {
      if (s[i] == 'p') {
        --res;
      }
    } else {
      if (s[i] == 'g') {
        ++res;
      }
    }
  }
  std::cout << res << std::endl;
}