#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int val (char c) {
  if (c == '^') { return 1; }
  if (c == 'v') { return 2; }
  if (c == '<') { return 4; }
  if (c == '>') { return 8; }
  assert (0);
  return 0;
}

void solve (void) {
  int r, c;
  assert (scanf ("%d %d\n", &r, &c) == 2);

  static char s[200][200];
  int i, j;
  for (i = 0; i < r; i++) {
    assert (scanf ("%s", s[i]) == 1);
    assert ((int)strlen (s[i]) == c);
  }

  int res = 0;
  for (i = 0; i< r; i++)
    for (j = 0; j < c; j++)
      if (s[i][j] != '.') {
        
        int allow = 15;
        int k;
        
        k = i - 1;
        while (k >= 0 && s[k][j] == '.') { k --; }
        if (k < 0) { allow ^= 1; }

        k = i + 1;
        while (k < r && s[k][j] == '.') { k ++; }
        if (k >= r) { allow ^= 2; }
        
        k = j - 1;
        while (k >= 0 && s[i][k] == '.') { k --; }
        if (k < 0) { allow ^= 4; }

        k = j + 1;
        while (k < c && s[i][k] == '.') { k ++; }
        if (k >= c) { allow ^= 8; }

        if (!allow) {
          printf ("IMPOSSIBLE\n");
          return;
        }

        if (!(allow & val (s[i][j]))) {
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
  return 0;
}
