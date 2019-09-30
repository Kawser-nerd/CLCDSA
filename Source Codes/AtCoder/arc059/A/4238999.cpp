#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> a(N);
  for (auto& ai: a) scanf("%d", &ai);

  int res = 1e9;
  for (int t = -100; t <= 100; ++t) {
    int cur = 0;
    for (auto ai: a)
      cur += (ai-t) * (ai-t);
    res = std::min(res, cur);
  }
  printf("%d\n", res);
}