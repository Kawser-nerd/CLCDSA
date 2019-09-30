#include <iostream>
#include <string>

int main() {
  std::string O, E;
  std::cin >> O >> E;

  std::string res;
  for (size_t i = 0; i < O.length(); ++i) {
    res += O[i];
    if (i < E.length()) res += E[i];
  }
  std::cout << res << std::endl;
}