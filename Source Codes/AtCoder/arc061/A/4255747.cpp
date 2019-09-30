#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  intmax_t res = 0;
  for (int i = 0; i < (1 << (S.length()-1)); ++i) {
    intmax_t cur = S[0]-'0';
    for (size_t j = 1; j < S.length(); ++j) {
      if (i >> (j-1) & 1) {
        res += cur;
        cur = 0;
      }
      cur = cur*10 + S[j]-'0';
    }
    res += cur;
  }
  std::cout << res << std::endl;
}