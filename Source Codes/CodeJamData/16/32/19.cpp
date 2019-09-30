#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 50 + 10;

int n;
i64 m;

int ans[N][N];

int main() {
  int tcase;
  scanf("%d", &tcase);
  for (int tid = 1; tid <= tcase; ++tid) {
    scanf("%d%lld", &n, &m);
    printf("Case #%d: ", tid);
    if (m > (1LL << (n - 2))) {
      puts("IMPOSSIBLE");
      continue;
    }
    puts("POSSIBLE");
    memset(ans, 0, sizeof ans);
    for (int i = 2; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        ans[i][j] = 1;
    if (m == (1LL << (n - 2))) {
      for (int i = 2; i <= n; ++i) ans[1][i] = 1;
    } else {
      for (int i = 2; i < n; ++i) if (m >> (n - i - 1) & 1) ans[1][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) printf("%d", ans[i][j]);
      puts("");
    }
  }
  return 0;
}
