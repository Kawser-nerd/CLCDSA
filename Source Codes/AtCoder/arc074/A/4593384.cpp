#include <cstdio>
#include <cstdint>
#include <algorithm>

constexpr intmax_t INF = 1e10;

intmax_t f(intmax_t h, intmax_t w) {
  intmax_t res = INF;
  for (intmax_t i = 1; i < h; ++i) {
    intmax_t s0 = w*i;
    intmax_t s1 = (w/2)*(h-i);
    intmax_t s2 = (w-w/2)*(h-i);
    res = std::min(res, std::max({s0, s1, s2})-std::min({s0, s1, s2}));
  }
  return res;
}

int main() {
  intmax_t H, W;
  scanf("%jd %jd", &H, &W);

  if (H % 3 == 0 || W % 3 == 0)
    return puts("0"), 0;

  printf("%jd\n", std::min({H, W, f(H, W), f(W, H)}));
}