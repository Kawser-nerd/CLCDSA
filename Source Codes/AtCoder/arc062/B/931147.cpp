#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::string s;
  int w = 0;
  int g = 0;
  int p = 0;
  std::cin >> s;
  for (auto c : s) {
    if (c == 'p') {
      if (p < g) {
        ++p;
      } else {
        ++g;
        --w;
      }
    } else {
      if (p < g) {
        ++p;
        ++w;
      } else {
        ++g;
      }
    }
  }
  std::cout << w << std::endl;
  return 0;
}