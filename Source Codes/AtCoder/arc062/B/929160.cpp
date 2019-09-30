#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::string s;
  int w = 0;
  std::cin >> s;
  for (std::size_t i = 0; i < s.length(); ++i) {
    if (i < (s.length() + 1) / 2) {
      w += (s[i] == 'p'? -1: 0);
    } else {
      w += (s[i] == 'g'? +1: 0);
    }
  }
  std::cout << w << std::endl;
  return 0;
}