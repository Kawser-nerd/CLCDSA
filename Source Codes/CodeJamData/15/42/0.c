#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

void solve (void) {
  int n;
  double v, x;
  assert (scanf ("%d %lf %lf", &n, &v, &x) == 3);

  static double r[200];
  static double c[200];

  int i, j;
  double sum = 0;
  for (i = 0; i < n; i++) {
    assert (scanf ("%lf %lf", &r[i], &c[i]) == 2);
    sum += r[i];
  }

  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (c[i] > c[j]) {
        double t = c[i]; c[i] = c[j]; c[j] = t;
        t = r[i]; r[i] = r[j]; r[j] = t;
      }

  if ((int)(10000 * c[0]) > (int)(10000 *x)) {
    printf ("IMPOSSIBLE\n");
    return;
  }

  if ((int)(10000 * c[n - 1]) < (int)(10000 *x)) {
    printf ("IMPOSSIBLE\n");
    return;
  }

  assert (sum > 0);

  long double t1 = v / sum;
  long double t2 = 1e100;

  int step = 0;
  for (step = 0; step < 10000; step ++) {
    long double t = (t1 + t2) / 2;

    long double mi = 0;
    long double rest = v;
    for (i = 0; i < n; i++) {
      long double x = rest / r[i];
      if (x > t) { x = t; }
      rest -= r[i] * x;
      mi += c[i] * r[i] * x;
    }
   
    assert (rest < 1e-8);
    long double ma = 0;
    rest = v;
    for (i = n - 1; i >= 0; i--) {
      long double x = rest / r[i];
      if (x > t) { x = t; }
      rest -= r[i] * x;
      ma += c[i] * r[i] * x;
    }
    assert (rest < 1e-8);

    //printf ("%lf %lf %lf\n", mi, ma, t);
    if (mi <= x * v * (1 + 1e-12) && ma >= x * v * (1 - 1e-12)) {
      t2 = t;
    } else {
      t1 = t;
    }
  }
  if (t2 <= 1e50) {
    printf ("%.8lf\n", (double)t2);
  } else {
    printf ("IMPOSSIBLE\n");
  }
}

int main () {
  int _;
  assert (scanf ("%d\n", &_) == 1);
  int __;
  for (__ = 0; __ < _; __ ++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
