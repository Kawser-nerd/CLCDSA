#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> A(N), B(N);
  for (auto& ai: A) scanf("%d", &ai);
  for (auto& bi: B) scanf("%d", &bi);

  int res = 0;
  for (size_t i = 1; i <= N; ++i) {
    int a = std::accumulate(A.begin(), A.begin()+i, 0);
    int b = std::accumulate(B.begin()+(i-1), B.end(), 0);
    res = std::max(res, a+b);
  }
  printf("%d\n", res);
}