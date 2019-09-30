#include <stdio.h>
#include <assert.h>
#include <string.h>

int a[1000];
double c[10001][10001];
double q[10000];

void solve (void) {
  int n, x, y;
  scanf ("%d%d%d", &n, &x, &y);
  if (x < 0) { x = -x; }
  int level = (x + y) / 2;
  int count = level + 2 * (level * (level - 1));
  if (count >= n) { 
    printf ("0\n");
    return;
  }
  int d = n - count;
  if (d >= 2 * level + y + 1) {
    printf ("1\n");
    return;
  }
  if (d <= y) {
    printf ("0\n");
    return;
  }
  if (y == 2 * level) {
    printf ("0\n");
    return;
  }
  double e = 0;
  int i;
  for (i = 0; i <= y; i++) {
    //if (d - i <= 2 * level) {
      e += c[d][i];
    //}
  }
  printf ("%lf\n", 1 - e);
}

int main () {
  int i, j;
  c[0][0] = 1;
  for (i = 1; i<= 10000; i++) {
    c[i][i] = c[i - 1][i - 1] / 2;
    for (j = 0; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) / 2;
    }
  }
  int _;
  assert (scanf ("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
