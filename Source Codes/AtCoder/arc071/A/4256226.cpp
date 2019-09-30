#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  size_t n;
  std::cin >> n;

  std::vector<std::vector<int>> fr(n, std::vector<int>(26));
  for (size_t i = 0; i < n; ++i) {
    std::string S;
    std::cin >> S;
    for (auto c: S) ++fr[i][c-'a'];
  }

  std::string res;
  for (size_t j = 'a'; j <= 'z'; ++j) {
    int cur = 50;
    for (size_t i = 0; i < n; ++i)
      cur = std::min(cur, fr[i][j-'a']);

    res += std::string(cur, j);
  }

  std::cout << res << std::endl;
}