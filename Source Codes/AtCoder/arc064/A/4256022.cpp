#include <cstdio>
#include <cstdint>
#include <vector>

int main() {
  size_t N;
  int x;
  scanf("%zu %d", &N, &x);

  std::vector<int> a(N);
  for (auto& ai: a) scanf("%d", &ai);

  intmax_t res = 0;
  if (a[0] > x) {
    res = a[0]-x;
    a[0] = x;
  }
  for (size_t i = 1; i < N; ++i) {
    if (a[i]+a[i-1] > x) {
      int d = a[i]+a[i-1]-x;
      res += d;
      a[i] -= d;
    }
  }
  printf("%jd\n", res);
}