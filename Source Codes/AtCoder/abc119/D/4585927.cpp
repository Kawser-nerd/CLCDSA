#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
  size_t A, B, Q;
  scanf("%zu %zu %zu", &A, &B, &Q);

  intmax_t INF = 1e12;

  std::vector<intmax_t> s(A), t(B);
  for (auto& si: s) scanf("%jd", &si);
  for (auto& tj: t) scanf("%jd", &tj);

  s.insert(s.begin(), -INF);
  s.push_back(INF);
  t.insert(t.begin(), -INF);
  t.push_back(INF);

  for (size_t i = 0; i < Q; ++i) {
    intmax_t x;
    scanf("%jd", &x);

    auto si = std::lower_bound(s.begin(), s.end(), x);
    intmax_t s1 = *si;
    intmax_t s0 = *--si;

    auto ti = std::lower_bound(t.begin(), t.end(), x);
    intmax_t t1 = *ti;
    intmax_t t0 = *--ti;

    intmax_t res = std::min({std::abs(x-std::max(s1, t1)),
                             std::abs(x-std::min(s0, t0)),
                             std::abs(x-s1) + std::abs(s1-t0),
                             std::abs(x-s0) + std::abs(s0-t1),
                             std::abs(x-t1) + std::abs(t1-s0),
                             std::abs(x-t0) + std::abs(t0-s1)});
    printf("%jd\n", res);
  }
}