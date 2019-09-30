#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t D;
  int G;
  scanf("%zu %d", &D, &G);

  std::vector<int> p(D), c(D);
  for (size_t i = 0; i < D; ++i)
    scanf("%d %d", &p[i], &c[i]);

  int res = 1e9;
  for (int i = 0; i < (1 << D); ++i) {
    int sum = 0;
    int cur = 0;
    for (size_t j = 0; j < D; ++j) {
      if (i >> j & 1) {
        sum += 100*(j+1) * p[j] + c[j];
        cur += p[j];
      }
    }
    for (size_t j = D; j--;) {
      if (i >> j & 1) continue;
      for (int k = 0; (k < p[j] && sum < G); ++k) {
        sum += 100*(j+1);
        ++cur;
      }
    }
    res = std::min(res, cur);
  }

  printf("%d\n", res);
}