#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
  int n, l, q, a, b, left, right;
  int x[100000];
  std::vector<int> next[30];
  std::scanf("%d", &n);
  for (int ni = 0; ni < n; ++ni) {
    std::scanf("%d", &x[ni]);
  }
  std::scanf("%d%d", &l, &q);
  next[0].resize(n);
  for (int ni = 0; ni < n; ++ni) {
    int lower = ni;
    int upper = n;
    while (upper - lower > 1) {
      int pos = (lower + upper) / 2;
      if (x[pos] - x[ni] <= l) {
        lower = pos;
      } else {
        upper = pos;
      }
    }
    next[0][ni] = lower;
  }
  for (int k = 1; k < 30; ++k) {
    next[k].resize(n);
    for (int ni = 0; ni < n; ++ni) {
      next[k][ni] = next[k - 1][next[k - 1][ni]];
    }
  }
  for (int qi = 0; qi < q; ++qi) {
    int ans = 0;
    std::scanf("%d%d", &a, &b);
    left = std::min(a - 1, b - 1);
    right = std::max(a - 1, b - 1);
    for (int k = 29; k >= 0; --k) {
      if (next[k][left] < right) {
        left = next[k][left];
        ans += (1 << k);
      }
    }
    while (left < right) {
      left = next[0][left];
      ++ans;
    }
    std::printf("%d\n", ans);
  }
  return 0;
}