#include <iostream>
#include <vector>

int main() {
  unsigned N;
  long long A, B, C, D;
  std::cin >> N >> A >> B >> C >> D;
  long long diff = std::abs(A - B);
  long long min = C * (N - 1);
  long long max = D * (N - 1);
  for (unsigned i = 0; i < N; ++i) {
    if (min <= diff && diff <= max) {
      std::cout << "YES" << std::endl;
      return 0;
    }
    min -= C + D;
    max -= C + D;
  }
  std::cout << "NO" << std::endl;
  return 0;
}