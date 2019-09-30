#include <iostream>
#include <set>
#include <string>
#include <algorithm>

int main() {
  std::string s;
  size_t K;
  std::cin >> s >> K;

  std::set<std::string> cand;
  for (size_t i = 0; i < s.length(); ++i)
    for (size_t j = 1; j <= K; ++j)
      if (i+j <= s.length())
        cand.insert(s.substr(i, j));

  auto it = cand.begin();
  std::advance(it, K-1);
  std::cout << *it << std::endl;
}