#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;
  S.erase(std::unique(S.begin(), S.end()), S.end());
  std::cout << (S.length()-1) << std::endl;
}