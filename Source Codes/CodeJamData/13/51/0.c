#include <stdio.h>
#include <assert.h>
#include <string.h>


void solve (void) {
  int n;
  long long b;
  static long long x[37];
  scanf ("%lld%d", &b, &n);
  int s = 37 - n;
  int i, j;
  for (i = 0; i < n; i++) {
    scanf ("%lld", &x[i]);
  }
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (x[i] > x[j]) {
        long long t = x[i]; x[i] = x[j]; x[j] = t;
      }
  for (i = n - 1; i >= 0; i--) {
    x[i + s] = x[i];
  }
  for (i = 0; i < s; i++)
    x[i] = 0;
  double best = 0;
  for (i = 1; i <= 36; i++) {
    long long l = x[i - 1] - 1;
    long long r = x[36];
    long long be = -1;
    long long bf = -1;
    while (r - l > 1) {
      long long t = (r + l) >> 1;
      long long e = 0;
      long long f = 0;
      for (j = 0; j < i; j++) {
        assert (x[j] <= t);
        e += t - x[j];
      }
      for (j = i; j <= 36; j ++) if (x[j] <= t + 1) {
        f += t + 1 - x[j];
      }
      if (e + f <= b) {
        l = t;
        be = e;
        bf = f;
      } else {
        r = t;
      }
    }
    if (l >= x[i - 1]) {
      double b = (be * 36) * 1.0 / i - bf - be;
      if (b > best) {
        best = b;
      }
    }
  }
  printf ("%lf\n", best);
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
