#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  int n;
  std::string s;
  std::cin >> n;
  std::vector<std::size_t> min_counter(26, 1e8);
  for (std::size_t i = 0; i < std::size_t(n); ++i) {
    std::vector<std::size_t> counter(26, 0);
    std::cin >> s;
    for (auto c : s) ++counter[c - 'a'];
    for (int i = 0; i < 26; ++i) min_counter[i] = std::min(min_counter[i], counter[i]);
  }
  for (int i = 0; i < 26; ++i) std::cout << std::string(min_counter[i], 'a' + i);
  std::cout << std::endl;
  return 0;
}