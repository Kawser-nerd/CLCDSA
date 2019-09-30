#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void solve (void) {
  int n, p;
  assert (scanf ("%d %d\n", &n, &p) == 2);

  assert (!(n & 1));
  assert (p <= (1 << (n / 2 - 2)));

  long long x[11];
  int i;
  for (i = 2; i <= 10; i++) {
    x[i] = i;
    int j;
    for (j = 0; j < n / 2 - 1; j ++) {
      x[i] *= i;
    }
    x[i] ++;
  }

  printf ("\n");
  for (i = 0; i < p; i++) {
    int j;
    for (j = 0; j < 2; j ++) {
      printf ("1");
      int k;
      for (k = 0; k < (n / 2) - 2; k++) {
        if (i & (1 << k)) {
          printf ("1");
        } else {
          printf ("0");
        }
      }
      printf ("1");
    }
    for (j = 2; j <= 10; j++) {
      printf (" %lld", x[j]);
    }
    printf ("\n");
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
}
