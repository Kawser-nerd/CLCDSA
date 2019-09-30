#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void solve (void) {
  int n;
  assert (scanf ("%d", &n) == 1);

  if (!n) {
    printf ("INSOMNIA\n");
    return;
  }

  int m = n;
  int c[10];
  int r = 10;
  memset (c, 0, sizeof (c));
  while (r > 0) {
    int mm = m;
    while (mm) {
      int x = mm % 10;
      if (!c[x]) {
        r --;
        c[x] = 1;
      }
      mm /= 10;
    }
    m += n;
  }
  printf ("%d\n", m - n);
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
