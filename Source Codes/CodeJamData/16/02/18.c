#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void solve (void) {
  char s[1000];
  s[0] = 0;
  assert (scanf ("%s", s) == 1);
  int l = strlen (s);
  assert (l > 0);
  s[l] = '+';
  
  int res = 0;
  int i;
  for (i = 0; i < l; i++) {
    assert (s[i] == '+' || s[i] == '-');
    assert (s[i + 1] == '+' || s[i + 1] == '-');
    if (s[i] != s[i + 1]) {
      res ++;
    }
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
}
