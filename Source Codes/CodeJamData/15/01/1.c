#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

void solve (void) {
  static char s[10000];
  int l;
  assert (scanf ("%d %s\n", &l, s) == 2);
  assert ((int)strlen (s) == l + 1);
  int cur = 0;
  int dif = 0;
  int i;
  for (i = 0; i <= l; i++) {
    if (s[i] != '0' && cur < i) {
      dif += i - cur;
      cur = i;
    }
    cur += s[i] - '0';
  }
  printf ("%d\n", dif);
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
