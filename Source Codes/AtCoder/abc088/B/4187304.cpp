#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> a(N);
  for (auto& ai: a) scanf("%d", &ai);

  std::sort(a.rbegin(), a.rend());

  int res = 0;
  for (size_t i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      res += a[i];
    } else {
      res -= a[i];
    }
  }
  printf("%d\n", res);
}