#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 10 + 1;

int main() {
  int tcase;
  scanf("%d", &tcase);
  for (int tid = 1; tid <= tcase; ++tid) {
    static bool f[N][N], g[N][N], h[N][N];
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    memset(h, 0, sizeof h);
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("Case #%d: %d\n", tid, a * b * std::min(c, d));
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        for (int t = 0; t < c && t < d; ++t) {
          int k = (i + j + t) % c;
          printf("%d %d %d\n", i + 1, j + 1, k + 1);
        }
      }
    }
  }
  return 0;
}
