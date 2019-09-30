#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<std::vector<intmax_t>> A(N, std::vector<intmax_t>(N));
  for (auto& ai: A)
    for (auto& aij: ai) scanf("%jd", &aij);

  auto B = A;
  for (size_t k = 0; k < N; ++k)
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < N; ++j)
        B[i][j] = std::min(B[i][j], B[i][k]+B[k][j]);

  if (A != B)
    return puts("-1"), 0;

  intmax_t res = 0;
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j < N; ++j) {
      bool found = false;
      for (size_t k = 0; k < N; ++k) {
        if (k == i || k == j) continue;
        if (B[i][j] < B[i][k]+B[k][j]) continue;
        found = true;
        break;
      }
      if (!found)
        res += B[i][j];
    }

  printf("%jd\n", res/2);
}