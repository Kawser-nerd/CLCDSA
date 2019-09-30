#include <iostream>

int main() {
  const unsigned long long MOD = 1000000007;
  unsigned long long N, M;
  std::cin >> N >> M;
  if (N > M + 1 || M > N + 1) {
    std::cout << 0;
    return 0;
  }
  unsigned long long fact = 1;
  for (unsigned i = 2; i <= std::min(N, M); ++i) {
    fact *= i;
    fact %= MOD;
  }
  fact *= fact;
  fact %= MOD;
  if (N != M) {
    fact *= std::max(N, M);
    fact %= MOD;
  } else {
    fact *= 2;
    fact %= MOD;
  }
  std::cout << fact;
  return 0;
}