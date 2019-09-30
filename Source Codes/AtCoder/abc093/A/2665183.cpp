#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  sort(S.begin(), S.end());

  std::cout << (S == "abc" ? "Yes" : "No") << std::endl;
}