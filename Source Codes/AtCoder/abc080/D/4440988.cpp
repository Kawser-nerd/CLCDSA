#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t N, C;
  scanf("%zu %zu", &N, &C);

  std::vector<std::vector<int>> imos(C, std::vector<int>(100001));
  for (size_t i = 0; i < N; ++i) {
    size_t s, t, c;
    scanf("%zu %zu %zu", &s, &t, &c);
    --c;
    ++imos[c][s-1];
    --imos[c][t];
  }

  for (size_t i = 0; i < C; ++i)
    for (size_t j = 1; j <= 100000; ++j)
      imos[i][j] += imos[i][j-1];

  int res = 0;
  for (size_t i = 0; i <= 100000; ++i) {
    int cur = 0;
    for (size_t j = 0; j < C; ++j)
      cur += (imos[j][i]? 1:0);

    res = std::max(res, cur);
  }

  printf("%d\n", res);
}