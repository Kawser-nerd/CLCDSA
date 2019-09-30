#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;
  std::sort(S.begin(), S.end());
  for (size_t i = 1; i < S.length(); ++i)
    if (S[i-1] == S[i])
      return (std::cout << "no" << std::endl), 0;

  std::cout << "yes" << std::endl;
}