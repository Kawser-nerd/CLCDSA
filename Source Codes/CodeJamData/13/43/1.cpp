#include <stdio.h>

const int N = 2424;

int g[N][N], x[N], id[N], a[N], b[N], deg[N], ans[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d:", qq);
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++) g[i][j] = 0;
    for (int r=0;r<2;r++) {
      for (int i=0;i<n;i++) id[i] = (r == 0 ? i : n-i-1);
      for (int i=0;i<n;i++) scanf("%d", a+id[i]);
      int m = 0;
      for (int i=0;i<n;i++) {
        if (a[i] <= m) {
          g[id[i]][id[b[a[i]]]] = 1;
        }
        if (a[i] > 1) {
          g[id[b[a[i]-1]]][id[i]] = 1;
        }
        b[a[i]] = i;
        if (a[i] > m) m = a[i];
      }
    }
    for (int i=0;i<n;i++) deg[i] = 0;
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++) deg[j] += g[i][j];
    int b = 1, e = 0;
    for (int i=0;i<n;i++)
      if (deg[i] == 0) x[++e] = i;
    while (b <= e) {
      for (int j=0;j<n;j++)
        if (g[x[b]][j]) {
          deg[j]--;
          if (deg[j] == 0) x[++e] = j;
        }
      b++;
    }
    bool dd = true;
    while (dd) {
      dd = false;
      for (int i=1;i<n;i++)
        if (x[i] > x[i+1] && !g[x[i]][x[i+1]]) {
          dd = true;
          int tmp = x[i];
          x[i] = x[i+1];
          x[i+1] = tmp;
        }
    }
    for (int i=1;i<=n;i++) ans[x[i]] = i;
    for (int i=0;i<n;i++) printf(" %d", ans[i]);
    printf("\n");
  }
  return 0;
}
