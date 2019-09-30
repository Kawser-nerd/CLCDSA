#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

void solve (void) {
  int c, d, v;
  assert (scanf ("%d %d %d", &c, &d, &v) == 3);
  static int val[1000];
  int i;
  for (i = 0; i < d; i++) {
    assert (scanf ("%d", &val[i]) == 1);
  }

  long long max = 0;
  int count = 0;
  int cur = 0;
  while (max < v) {
    if (cur < d && val[cur] <= max + 1) {
      max += c * (long long)val[cur];
      cur ++;
    } else {
      count ++;
      max += c * (long long)(max + 1);
    }
  }
  printf ("%d\n", count);
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
