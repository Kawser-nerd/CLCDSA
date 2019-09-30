#include <iostream>
#include <string>
#include <algorithm>

int main() {
  size_t N;
  std::string S;
  std::cin >> N >> S;

  int res = 0;
  for (size_t i = 1; i+1 < N; ++i) {
    int cur = 0;
    std::string s = S.substr(0, i);
    std::string t = S.substr(i);
    for (char c = 'a'; c <= 'z'; ++c)
      if (std::count(s.begin(), s.end(), c) && std::count(t.begin(), t.end(), c))
        ++cur;

    res = std::max(res, cur);
  }
  std::cout << res << std::endl;
}