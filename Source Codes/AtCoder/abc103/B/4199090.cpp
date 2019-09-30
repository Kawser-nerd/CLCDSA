#include <iostream>
#include <string>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  for (size_t i = 0; i < S.length(); ++i) {
    if (S == T)
      return (std::cout << "Yes" << std::endl), 0;
    S = S.back() + S;
    S.pop_back();
  }

  std::cout << "No" << std::endl;
}