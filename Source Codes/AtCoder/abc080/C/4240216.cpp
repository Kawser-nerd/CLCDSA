#include <cstdio>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<std::vector<int>> F(N, std::vector<int>(10));
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j < 10; ++j)
      scanf("%d", &F[i][j]);

  std::vector<std::vector<int>> P(N, std::vector<int>(11));
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j <= 10; ++j)
      scanf("%d", &P[i][j]);

  int res = -1e9;
  for (int i = 1; i < (1 << 10); ++i) {
    int cur = 0;
    for (size_t j = 0; j < N; ++j) {
      int p = 0;
      for (size_t k = 0; k < 10; ++k)
        if (i >> k & 1 && F[j][k]) ++p;
      cur += P[j][p];
    }
    res = std::max(res, cur);
  }
  printf("%d\n", res);
}