#include <stdio.h>
#include <assert.h>
#include <string.h>

int c[2001][2001];
int a[2001];
int b[2001];
int r[2001];
int g[2001];
int d[2001];

void solve (void) {
  int n;
  scanf ("%d", &n);
  int i, j;
  for (i = 0; i < n; i++) {
    scanf ("%d", &a[i]);
  }
  for (j = 0; j < n; j++) {
    scanf ("%d", &b[j]);
  }
  for (i = 0; i < n; i++) {
    d[i] = 0;
    for (j = 0; j < n; j++) 
      c[i][j] = 0;
  }

  for (i = 0; i < n; i++) {
    int x = -1; int y = -1;
    for (j = 0; j < i; j++) {
      if (a[j] >= a[i]) {
        assert (c[j][i] >= 0);
        if (!c[j][i]) {
          d[j] ++;
        }
        c[j][i] = 1;
        c[i][j] = -1;
      }
      if (a[j] == a[i] - 1) { x = j; }
    }
    assert (x >= 0 || a[i] == 1);
    if (x >= 0) {
      assert (c[x][i] <= 0);
      if (!c[x][i]) {
        d[i] ++;
        c[x][i] = -1;
        c[i][x] = 1;
      }
    }
    for (j = n - 1; j > i; j--) {
      if (b[j] >= b[i]) {
        assert (c[i][j] <= 0);
        if (!c[i][j]) {
          d[j] ++;
        }
        c[j][i] = 1;
        c[i][j] = -1;
      }
      if (b[j] == b[i] - 1) { y = j; }
    }
    assert (y >= 0 || b[i] == 1);
    if (y >= 0) {
      assert (c[y][i] <= 0);
      if (!c[y][i]) {
        d[i] ++;
        c[y][i] = -1;
        c[i][y] = 1;
      }
    }
  }
  for (i = 0; i < n; i++) g[i] = 0;
  int cc;
  for (cc = 0; cc < n; cc ++) {
    for (i = 0; i < n; i++) if (!g[i] && !d[i]) {
      r[i] = cc + 1;
      for (j = 0; j < n; j++) if (!g[j] && c[i][j] < 0) {
        d[j] --;
      }
      g[i] = 1;
      break;
    }
  }
  for (i = 0; i < n; i ++) {
    if (i != 0) { printf (" "); }
    printf ("%d", r[i]);
  }
  printf ("\n");
  fflush (stdout);
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
