#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

void solve (void) {
  int r, c, w;
  assert (scanf ("%d %d %d", &r, &c, &w) == 3);
  int res = (r - 1) * (c / w);
  res += c / w + w;
  if (c % w == 0) {
    res --;
  }
  printf ("%d\n", res);
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
