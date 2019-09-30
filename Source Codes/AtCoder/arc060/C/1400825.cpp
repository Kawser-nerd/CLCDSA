#include <iostream>
#include <vector>
#include <cmath>

int main() {
  unsigned N;
  std::cin >> N;
  auto X = N;
  unsigned logN = 1;
  while (X) {
    ++logN;
    X >>= 1;
  }
  std::vector<unsigned> x(N);
  std::vector<std::vector<unsigned>> reach(logN, std::vector<unsigned>(N));
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> x[i];
  }
  unsigned L;
  std::cin >> L;
  unsigned start = 0;
  for (unsigned i = 1; i < N; ++i) {
    while (start < i) {
      if (x[i] - x[start] <= L) {
        reach[0][start] = i;
        break;
      } else {
        reach[0][start] = i - 1;
        ++start;
      }
    }
  }
  for (unsigned i = start + 1; i < N; ++i) {
    reach[0][i] = N - 1;
  }
  for (unsigned r = 1; r < logN; ++r) {
    for (unsigned i = 0; i < N; ++i) {
      reach[r][i] = reach[r - 1][reach[r - 1][i]];
    }
  }
  unsigned Q;
  std::cin >> Q;
  for (unsigned i = 0; i < Q; ++i) {
    unsigned a, b;
    std::cin >> a >> b;
    if (a > b) { std::swap(a, b); }
    --a;
    --b;
    unsigned sum = 0;
    unsigned ans = 0;
    for (unsigned j = logN; j-- > 0; ) {
      if (reach[j][a] < b) {
        a = reach[j][a];
        sum += std::pow(2u, j);
      } else if (reach[j][a] >= b) {
        ans = sum + std::pow(2u, j);
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}