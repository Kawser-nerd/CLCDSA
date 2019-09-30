#include <stdio.h>

const long long inf = 1001001001001LL;
const long long N = 4010;

long long g[N][N];
long long ss[N], ff[N], d1[N], d2[N], pred[N], last[N], edge[N];
bool b[N];
long long mx[N], r[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  long long tt;
  scanf("%I64d", &tt);
  for (long long qq=1;qq<=tt;qq++) {
    printf("Case #%I64d: ", qq);
    long long n, m, p;
    scanf("%I64d %I64d %I64d", &n, &m, &p);
    for (long long i=1;i<=n;i++) last[i] = 0;
    for (long long i=1;i<=m;i++) {
      scanf("%d %d %d %d", ss+i, ff+i, d1+i, d2+i);
      pred[i] = last[ss[i]];
      last[ss[i]] = i;
    }
    for (long long i=1;i<=p;i++) scanf("%d", edge+i);
    for (long long i=1;i<=n;i++)
      for (long long j=1;j<=n;j++) g[i][j] = (i == j ? 0 : inf);
    for (long long i=1;i<=m;i++)
      if (d2[i] < g[ss[i]][ff[i]]) {
        g[ss[i]][ff[i]] = d2[i];
      }
    for (long long k=1;k<=n;k++)
      for (long long i=1;i<=n;i++)
        for (long long j=1;j<=n;j++)
          if (g[i][k]+g[k][j] < g[i][j]) g[i][j] = g[i][k]+g[k][j];
    long long ll = 0, rr = p;
    while (ll < rr) {
      long long mid = (ll+rr+1) >> 1;
      for (long long i=1;i<=n;i++) mx[i] = inf;
      long long time = 0;
      for (long long i=mid;i>=1;i--) {
        time += d1[edge[i]];
        long long ver = ss[edge[i]];
        for (long long j=1;j<=n;j++)
          if (g[ver][j]-time < mx[j]) mx[j] = g[ver][j]-time;
      }
      for (long long i=1;i<=n;i++) r[i] = inf+10, b[i] = true;
      r[ff[edge[mid]]] = 0;
      for (long long it=1;it<=n;it++) {
        long long mn = inf+100, km = -1;
        for (long long i=1;i<=n;i++)
          if (b[i] && r[i] < mn) {
            mn = r[i];
            km = i;
          }
        b[km] = false;
        if (mn > mx[km]) continue;
        long long j = last[km];
        while (j > 0) {
          if (mn+d1[j] < r[ff[j]]) {
            r[ff[j]] = mn+d1[j];
          }
          j = pred[j];
        }
      }
      if (r[2] <= mx[2]) ll = mid;
      else rr = mid-1;
    }
    if (ll == p) printf("Looks Good To Me\n");
    else printf("%I64d\n", edge[ll+1]);
    fflush(stdout);
  }
  return 0;
}
