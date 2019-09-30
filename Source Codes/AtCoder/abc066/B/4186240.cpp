#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  S.pop_back();
  if (S.length() % 2 > 0) S.pop_back();
  size_t n = S.length() / 2;
  while (true) {
    if (S.substr(0, n) == S.substr(n)) break;
    S.pop_back();
    S.pop_back();
    --n;
  }
  std::cout << S.length() << std::endl;
}