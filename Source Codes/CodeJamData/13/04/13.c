#include <stdio.h>
#include <assert.h>
#include <string.h>

int start[300];
int t[30];
int d[30];
int e[30][100];
int res[(1 << 20)];

void solve (void) {
  int i, j, k, n;
  assert (scanf ("%d%d\n", &k, &n) == 2);
  for (i = 0; i <= 200; i++)
    start[i] = 0;
  for (i = 0; i < k; i++) {
    int a;
    scanf ("%d", &a);
    start[a] ++;
  }
  for (i = 0; i < n; i++) {
    scanf ("%d", &t[i]);
    scanf ("%d", &d[i]);
    for (j = 0; j < d[i]; j++)
      scanf ("%d", &e[i][j]);
  }
  res[0] = 0;
  int z[201];
  for (i = 1; i < (1 << n); i++) {
    for (j = 0; j <= 200; j++) { z[j] = start[j]; }
    for (j = 0; j < n; j++) if (!(i & (1 << j))) {
      for (k = 0; k < d[j]; k ++) 
        z[e[j][k]] ++;
      z[t[j]] --;
    }
    int ok = 0;
    for (j = 0; j < n; j++) if ((i & (1 << j)) && z[t[j]] > 0) {
      if (res[i ^ (1 << j)] >= 0) {
        res[i] = j;
        ok = 1;
        break;
      }
    }
    if (!ok) {
      res[i] = -1;
    }
  }
  int cc = (1 << n) - 1;
  if (res[cc] == -1) {
    printf ("IMPOSSIBLE\n");
    return;
  }
  while (cc > 0) {
    assert (res[cc] >= 0);
    if (cc != (1 << n) - 1) { printf (" "); }
    printf ("%d", res[cc] + 1);
    assert (cc & (1 << res[cc]));
    cc ^= (1 << res[cc]);
  }
  printf ("\n");
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
