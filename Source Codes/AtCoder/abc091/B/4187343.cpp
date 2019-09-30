#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  std::map<std::string, int> a;
  for (int i = 0; i < N; ++i) {
    std::string s;
    std::cin >> s;
    ++a[s];
  }

  int M;
  std::cin >> M;
  for (int i = 0; i < M; ++i) {
    std::string t;
    std::cin >> t;
    --a[t];
  }

  int res = 0;
  for (auto& p: a)
    res = std::max(res, p.second);

  std::cout << res << std::endl;
}