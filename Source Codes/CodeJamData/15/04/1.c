#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

void solve (void) {
  int x, r, c;
  assert (scanf ("%d %d %d", &x, &r, &c) == 3);
  if (x >= 7 || ((r * c) % x) != 0) {
    printf ("RICHARD\n");
    return;
  }
  if (x <= 2) {
    printf ("GABRIEL\n");
    return;
  }
  if (r > c) {
    int t = r; r = c; c = t;
  }

  if (r <= 1) {
    printf ("RICHARD\n");
    return;
  }
  if (x == 3) {
    printf ("GABRIEL\n");
    return;
  }
  if (r <= 2) {
    printf ("RICHARD\n");
    return;
  }
  if (x == 4) {
    printf ("GABRIEL\n");
    return;
  }
  if (x == 5) {
    if (r == 3 && c == 5) {
      printf ("RICHARD\n");
      return;
    }
    printf ("GABRIEL\n");
    return;
  }
  if (x == 6) {
    if (r > 3) {
      printf ("GABRIEL\n");
      return;
    }
    assert (r == 3);
    printf ("RICHARD\n");
    return;
  }
  assert (0);
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
