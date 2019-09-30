#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

template <class Tp>
constexpr Tp inf = Tp(1) << (8*sizeof(Tp)-3);

int main() {
  size_t N, M, R;
  scanf("%zu %zu %zu", &N, &M, &R);

  std::vector<intmax_t> r(R);
  for (auto& ri: r) {
    scanf("%jd", &ri);
    --ri;
  }

  std::vector<std::vector<intmax_t>> g(N, std::vector<intmax_t>(N, inf<intmax_t>));
  for (size_t i = 0; i < M; ++i) {
    size_t A, B;
    intmax_t C;
    scanf("%zu %zu %jd", &A, &B, &C);
    --A;
    --B;
    g[A][B] = g[B][A] = C;
  }

  for (size_t k = 0; k < N; ++k)
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < N; ++j)
        g[i][j] = std::min(g[i][j], g[i][k]+g[k][j]);

  std::sort(r.begin(), r.end());
  intmax_t res = inf<intmax_t>;
  do {
    intmax_t cur = 0;
    for (size_t i = 1; i < R; ++i) cur += g[r[i-1]][r[i]];
    res = std::min(res, cur);
  } while (std::next_permutation(r.begin(), r.end()));

  printf("%jd\n", res);
}