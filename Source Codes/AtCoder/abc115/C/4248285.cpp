#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t N, K;
  scanf("%zu %zu", &N, &K);

  std::vector<int> h(N);
  for (auto& hi: h) scanf("%d", &hi);

  std::sort(h.begin(), h.end());
  int res = 1e9;
  for (size_t i = K-1; i < N; ++i)
    res = std::min(res, h[i]-h[i-(K-1)]);

  printf("%d\n", res);
}