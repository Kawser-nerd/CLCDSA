#include <stdio.h>
#include <assert.h>
#include <string.h>

long long M = 1000002013;

long long count (long long n, long long v) {
  return (v * n - (v * (v - 1)) / 2) % M;
}

int sn[1001], sp[1001], en[1001], ep[1001], stn[1001], stp[1001];

void solve (void) {
  int n, m;
  scanf ("%d %d", &n, &m);
  int i, j;
  long long v = 0;
  for (i = 0; i < m; i++) {
    int x, y, t;
    assert (scanf ("%d%d%d", &x, &y, &t) == 3);
    sp[i] = x;
    sn[i] = t;
    ep[i] = y;
    en[i] = t;
    v += t * count (n, y - x);
    v %= M;
  }
  for (i = 0; i < m; i++)
    for (j = i + 1; j < m; j ++) if (sp[i] > sp[j]) {
      int t;
      t = sp[i]; sp[i] = sp[j]; sp[j] = t;
      t = sn[i]; sn[i] = sn[j]; sn[j] = t;
    }
  for (i = 0; i < m; i++)
    for (j = i + 1; j < m; j ++) if (ep[i] > ep[j]) {
      int t;
      t = ep[i]; ep[i] = ep[j]; ep[j] = t;
      t = en[i]; en[i] = en[j]; en[j] = t;
    }
  long long w = 0;
  int p1 = 0; 
  int p2 = 0;
  int cc = -1;
  while (p1 < m || p2 < m) {
    if (p2 == m || (p1 < m && sp[p1] <= ep[p2])) {
      ++ cc;
      stp[cc] = sp[p1];
      stn[cc] = sn[p1];
      p1 ++;
    } else {
      int p = ep[p2];
      int c = en[p2];
      while (c > 0) {
        assert (cc >= 0);
        if (stn[cc] >= c) {
          w += c * count (n, p - stp[cc]);
          w %= M;
          stn[cc] -= c;
          c = 0;
        } else {
          w += stn[cc] * count (n, p - stp[cc]);
          w %= M;
          c -= stn[cc];
          cc --;
        }
      }
      p2 ++;
    }
  }
  v -= w;
  if (v < 0) { v += M; }
  printf ("%lld\n", v);
}

int main () {
  int _;
  assert (scanf ("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
