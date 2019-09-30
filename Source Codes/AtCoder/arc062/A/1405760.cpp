#include <iostream>

int main() {
  unsigned N;
  std::cin >> N;
  unsigned long long TT = 0, AA = 0;
  for (unsigned i = 0; i < N; ++i) {
    unsigned long long T, A;
    std::cin >> T >> A;
    if (i == 0) {
      TT = T;
      AA = A;
    }
    auto x = std::max({(TT - 1) / T, (AA - 1) / A}) + 1ull;
    TT = x * T;
    AA = x * A;
  }
  std::cout << TT + AA << std::endl;
  return 0;
}