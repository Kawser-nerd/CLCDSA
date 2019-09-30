#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  unsigned long N;
  std::cin >> N;
  std::vector<long long> x(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> x[i];
  }
  std::vector<long long> y(x);
  std::sort(x.begin(), x.end());
  auto med0 = x[N / 2 - 1];
  auto med1 = x[N / 2];
  for (unsigned i = 0; i < N; ++i) {
    std::cout << (y[i] <= med0 ? med1 : med0) << std::endl;
  }
  return 0;
}