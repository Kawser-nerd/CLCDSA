#include <cstdio>
#include <cstdint>
#include <vector>

int main() {
  intmax_t N, X;
  scanf("%jd %jd", &N, &X);

  std::vector<intmax_t> pb(N+1);
  pb[0] = 1;
  for (intmax_t i = 1; i <= N; ++i)
    pb[i] = 2*pb[i-1] + 3;

  std::vector<intmax_t> p(N+1);
  p[0] = 1;
  for (intmax_t i = 1; i <= N; ++i)
    p[i] = 2*p[i-1] + 1;

  intmax_t res = 0;
  for (intmax_t i = N; i >= 0; --i) {
    if (i == 0) {
      if (X >= 1) ++res;
    } else if (X <= pb[i-1]+1) {
      --X;
    } else {
      res += p[i-1]+1;
      X -= pb[i-1]+2;
    }
  }

  printf("%jd\n", res);
}