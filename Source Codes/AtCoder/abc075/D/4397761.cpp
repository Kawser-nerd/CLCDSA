#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

int main() {
  size_t N, K;
  scanf("%zu %zu", &N, &K);

  std::vector<std::pair<intmax_t, intmax_t>> xy(N);
  std::vector<intmax_t> xs(N), ys(N);
  for (size_t i = 0; i < N; ++i) {
    scanf("%jd %jd", &xy[i].first, &xy[i].second);
    std::tie(xs[i], ys[i]) = xy[i];
  }

  intmax_t res = 9e18;
  for (auto x0: xs)
    for (auto x1: xs)
      for (auto y0: ys)
        for (auto y1: ys) {
          size_t cur = 0;
          for (const auto& xyi: xy) {
            intmax_t x, y;
            std::tie(x, y) = xyi;
            if (x0 <= x && x <= x1 && y0 <= y && y <= y1) ++cur;
          }

          if (cur < K) continue;
          res = std::min(res, (y1-y0)*(x1-x0));
        }

  printf("%jd\n", res);
}