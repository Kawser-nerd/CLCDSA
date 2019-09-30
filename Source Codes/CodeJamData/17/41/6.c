#include <stdio.h>

int g[105];
int cnt[5];

int main() {
  int t, i, ti, ni;
  scanf("%d", &t);
  for (ti = 1; ti <= t; ti++) {
    for (i = 0; i <= 3; i++) {
      cnt[i] = 0;
    }
    int n, p;
    scanf("%d %d", &n, &p);
    for (ni = 0; ni < n; ni++) {
      scanf("%d", &g[ni]);
      cnt[g[ni] % p]++;
    }
    int ans = cnt[0];
    if (p == 2) {
      ans += (cnt[1] + 1) / 2;
    } else { // p == 3
      int min = cnt[1];
      if (cnt[2] < min) {
        min = cnt[2];
      }
      ans += min;
      cnt[1] -= min;
      cnt[2] -= min;
      ans += (cnt[1] + 2) / 3;
      ans += (cnt[2] + 2) / 3;
    }
    printf("Case #%d: %d\n", ti, ans);
  }
  return 0;
}
