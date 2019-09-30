#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void solve (void) {
  int k, c, s;
  assert (scanf ("%d%d%d", &k, &c, &s) == 3);

  int best = (k + c - 1) / c;
  if (s < best) {
    printf ("IMPOSSIBLE\n");
    return;
  }

  int t = 0;
  int i;
  for (i = 0; i < best; i++) {
    long long p = 0;
    int j;
    for (j = 0; j < c; j++) {
      p = p * k + (t ++);
      if (t == k) { t = k - 1; }
    }
    if (i != 0) {
      printf (" ");
    }
    printf ("%lld", p + 1);
  }
  printf ("\n");
}

int main () {
  int _;
  assert (scanf ("%d\n", &_) == 1);
  int __;
  for (__ = 0; __ < _; __ ++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
}
