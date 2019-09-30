#include <iostream>

int main() {
  unsigned long long N, M;
  std::cin >> N >> M;
  unsigned long long ans = M * 1900 + (N - M) * 100;
  for (unsigned i = 0; i < M; ++i) {
    ans *= 2;
  }
  std::cout << ans << std::endl;
  return 0;
}