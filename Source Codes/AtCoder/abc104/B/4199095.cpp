#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  if (S[0] != 'A') {
    std::cout << "WA" << std::endl;
  } else if (std::count(S.begin()+2, S.end()-1, 'C') != 1) {
    std::cout << "WA" << std::endl;
  } else {
    for (size_t i = 1; i < S.length(); ++i)
      if (!(S[i] == 'C' || islower(S[i])))
        return (std::cout << "WA" << std::endl), 0;
    std::cout << "AC" << std::endl;
  }
}