#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

void solve (void) {
  int D;
  assert (scanf ("%d", &D) == 1);
  static int p[1001], q[1001];
  int i, j;
  bzero (p, sizeof (p));
  for (i = 0; i < D; i++) {
    int pp;
    assert (scanf ("%d", &pp) == 1);
    p[pp] ++;
  }

  int best = 1000;
  for (i = 1; i <= 1000; i++) {
    int res = i;
    for (j = 1; j <= 1000; j++) {
      if (j <= i) {
        q[j] = 0;
      } else {
        q[j] = q[j - i] + 1;
      }
      res += p[j] * q[j];
    }
    if (res < best) {
      best = res;
    }
  }
  printf ("%d\n", best);
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
