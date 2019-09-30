#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> A(N);
  for (auto& ai: A) scanf("%d", &ai);

  int res = 0;
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j < N; ++j)
      res = std::max(res, std::abs(A[i]-A[j]));

  printf("%d\n", res);
}