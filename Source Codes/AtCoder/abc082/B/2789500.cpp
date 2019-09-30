#include <iostream>
#include <string>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  std::sort(S.begin(), S.end());
  std::sort(T.begin(), T.end(), std::greater<char>());

  std::cout << (S < T ? "Yes" : "No") << std::endl;
}