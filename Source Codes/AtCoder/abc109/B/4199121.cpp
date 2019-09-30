#include <iostream>
#include <string>
#include <set>

int main() {
  size_t N;
  std::cin >> N;

  std::set<std::string> seen;
  std::string last = "^";
  for (size_t i = 0; i < N; ++i) {
    std::string W;
    std::cin >> W;

    if (seen.count(W))
      return (std::cout << "No" << std::endl), 0;
    if (i > 0 && last.back() != W.front())
      return (std::cout << "No" << std::endl), 0;

    last = W;
    seen.insert(W);
  }
  std::cout << "Yes" << std::endl;
}