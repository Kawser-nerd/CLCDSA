#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

bool valid(intmax_t k, const std::vector<intmax_t>& h, intmax_t a, intmax_t b) {
  intmax_t m = 0;
  a -= b;
  for (auto hi: h) {
    if (hi <= b*k) continue;
    m += (hi-b*k + a-1) / a;
  }
  return m <= k;
}

int main() {
  size_t N;
  intmax_t A, B;
  scanf("%zu %jd %jd", &N, &A, &B);

  std::vector<intmax_t> h(N);
  for (auto& hi: h) scanf("%jd", &hi);

  intmax_t lb = 0;
  intmax_t ub = 1e9+1;
  while (ub-lb > 1) {
    intmax_t mid = (lb+ub) >> 1;
    (valid(mid, h, A, B)? ub:lb) = mid;
  }
  printf("%jd\n", ub);
}