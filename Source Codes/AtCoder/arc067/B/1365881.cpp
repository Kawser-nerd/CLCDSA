#include <iostream>
#include <vector>

int main() {
  unsigned N, A, B;
  std::cin >> N >> A >> B;
  std::vector<unsigned> X(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> X[i];
  }
  unsigned long long ans = 0ull;
  for (unsigned i = 1; i < N; ++i) {
    if (X[i] - X[i-1] > B / A) {
      ans += B;
    } else {
      ans += (X[i] - X[i-1]) * A;
    }
  }
  std::cout << ans;
  return 0;
}