#include <iostream>
#include <vector>

std::vector<unsigned> z(const std::string &s) {
  std::vector<unsigned> ret(s.size());
  ret[0] = s.size();
  unsigned i = 1, j = 0;
  while (i < s.size()) {
    while (i + j < s.size() && s[j] == s[i + j]) { ++j; }
    ret[i] = j;
    unsigned k = 1;
    if (j == 0) {
      ++i;
      continue;
    }
    while (i + k < s.size() && k + ret[k] < j) {
      ret[i + k] = ret[k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return ret;
}

int main() {
  std::string s;
  std::cin >> s;
  auto Z_in = z(s);
  std::reverse(s.begin(), s.end());
  auto Z_rev = z(s);
  auto ans = 0ull;
  for (auto i = (s.size() + 2) / 2; i + 1 < s.size(); ++i) {
    auto x = Z_in[i];
    unsigned n = (unsigned) (s.size() - i);
    auto y = Z_rev[n];
    if (x > 0 && y > 0 && x + y >= s.size() - i) {
      ans += std::min(x, n - 1) + std::min(y, n - 1) - n + 1;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}