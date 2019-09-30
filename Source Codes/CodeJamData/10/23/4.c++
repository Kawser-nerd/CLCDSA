#include <cassert>
#include <cstdio>
#include <cstring>

const int maxn = 510;
const int modulo = 100003;

int d[maxn][maxn], d2[maxn][maxn];

// next time I'll try to learn haskell

int cnk( int n, int k ) {
  if (d2[n][k] != -1)
    return d2[n][k];
  if (n == 0)
    return d2[n][k] = (n == k);
  if (k == 0)
    return d2[n][k] = 1;
  return d2[n][k] = (cnk(n - 1, k) + cnk(n - 1, k - 1)) % modulo;
}

int f( int n, int k ) {
  if (d[n][k] != -1)
    return d[n][k];
  if (k == 1)
    return d[n][k] = 1;
  d[n][k] = 0;
  for (int s = 1; s < k; s++)
    d[n][k] += ((long long)f(k, s) * cnk(n - k - 1, k - s - 1)) % modulo;
  d[n][k] %= modulo;
  return d[n][k];
}

int solve( int n ) {
  int ans = 0;
  for (int k = 1; k < n; k++)
    ans += f(n, k);
  return ans % modulo;
}

int main() {
  memset(d, -1, sizeof(d));
  memset(d2, -1, sizeof(d2));
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int n;
    assert(scanf("%d", &n) == 1);
    printf("Case #%d: %d\n", tt, solve(n));
  }
  return 0;
}

