#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  int res = 1000;
  for (size_t i = 3; i <= S.length(); ++i) {
    std::string t(S.begin()+i-3, S.begin()+i);
    res = std::min(res, abs(std::stoi(t)-753));
  }
  std::cout << res << std::endl;
}