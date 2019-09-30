#include <cstdio>
#include <cstdint>
#include <map>

constexpr intmax_t MOD = 1e9+7;

int main() {
  int N;
  scanf("%d", &N);

  std::map<int, int> factor;
  for (int i = 2; i <= N; ++i) {
    int m = i;
    for (int j = 2; j*j <= m; ++j) {
      while (m % j == 0) {
        ++factor[j];
        m /= j;
      }
    }
    if (m > 1) ++factor[m];
  }

  intmax_t res = 1;
  for (auto& p: factor)
    (res *= p.second+1) %= MOD;

  printf("%jd\n", res);
}