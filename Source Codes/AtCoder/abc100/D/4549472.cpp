#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<intmax_t> x(N), y(N), z(N);
  for (size_t i = 0; i < N; ++i)
    scanf("%jd %jd %jd", &x[i], &y[i], &z[i]);

  intmax_t res = 0;
  for (int i = 0; i < 8; ++i) {
    std::vector<intmax_t> xyz(N);
    for (size_t j = 0; j < N; ++j) {
      intmax_t& cur = xyz[j];
      cur += ((i & 4)? x[j]:-x[j]);
      cur += ((i & 2)? y[j]:-y[j]);
      cur += ((i & 1)? z[j]:-z[j]);
    }
    std::sort(xyz.rbegin(), xyz.rend());
    res = std::max(res, std::accumulate(xyz.begin(), xyz.begin()+M, 0L));
  }
  printf("%jd\n", res);
}