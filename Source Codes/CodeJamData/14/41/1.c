#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int a[10000];
int b[10000];

int cmp (const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int _prev[10002];
int _next[10002];
int *prev = _prev + 1;
int *next = _next + 1;

void solve (void) {
  int n, x;
  scanf ("%d %d", &n, &x);
  int i;
  next[-1] = 0;
  for (i = 0; i < n; i++) {
    scanf ("%d", &a[i]);
    prev[i] = i - 1;
    next[i] = i + 1;
    b[i] = 0;
  }
  a[n] = 1000000000;
  prev[n] = n - 1;
  qsort (a, n, 4, cmp);
  int p1 = n - 1;
  int p2 = -1;
  int res = 0;
  for (i = 0; i < n - 1; i++) {
    assert (a[i] <= a[i + 1]);
  }

  while (p1 >= 0) {  
    while (p2 >= p1) {
      p2 = prev[p2];
    }
    if (!b[p1]) {
      while (next[p2] < p1 && a[next[p2]] + a[p1] <= x) {
        assert (p2 < next[p2]);
        p2 = next[p2];
      }
      if (p2 >= 0) {
        b[p2] = 1;
      }
      res ++;
      if (p2 >= 0) {
        next[prev[p2]] = next[p2];
        prev[next[p2]] = prev[p2];
        p2 = prev[p2];
      }
    }
    p1 --;
  }
  printf (" %d\n", res);
}

int main () {
  int _;
  assert (scanf ("%d", &_) == 1);
  int __;
  for (__ = 0; __ < _; __ ++) {
    printf ("Case #%d:", __ + 1);
    solve ();
  }
  return 0;
}
