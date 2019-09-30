#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int mult_arr[4][4] = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}};

int mult (int a, int b) {
  int sign = (a & 4) ^ (b & 4);
  return sign ^ mult_arr [a & 3][b & 3];
}

void solve (void) {
  long long x;
  int l;
  assert (scanf ("%d %lld\n", &l, &x) == 2);
  assert (l <= 1000000);
  static char s[1000000];
  assert (scanf ("%s\n", s) == 1);
  assert ((int)strlen (s) == l);
  static int a[1000000];
  int i, j;
  for (i = 0; i < l; i++) {
    if (s[i] == 'i') {
      a[i] = 1;
    } else if (s[i] == 'j') {
      a[i] = 2;
    } else if (s[i] == 'k') {
      a[i] = 3;
    } else {
      assert (0);
    }
  }
  int total = 0;
  for (i = 0; i < l; i++) {
    total = mult (total, a[i]);
  }
  int res = 0;
  int xx = x & 3;
  while (xx > 0) {
    res = mult (res, total);
    xx --;
  }
  if (res != 4) {
    printf ("NO\n");
    //fprintf (stderr, "(total mult = %d)\n", res);
    return;
  }

  int bi = l;
  int bix = 10;

  res = 0;
  for (i = 0; i < l; i++) {
    res = mult (res, a[i]);
    int r = res;
    for (j = 0; j < 4; j++) {
      if (r == 1) {
        if (bix > j) {
          bix = j;
          bi = i;
          break;
        }
      }
      r = mult (r, total);
    }
  }

  if (bix == 10) {
    printf ("NO\n");
    //fprintf (stderr, "bix = %d\n", bix);
    return;
  }

  int bj = l;
  int bjx = 10;

  res = 0;
  for (i = 0; i < l; i++) {
    if (i + bi + 1 < l) {
      res = mult (res, a[i + bi + 1]);
    } else {
      res = mult (res, a[i + bi + 1 - l]);
    }
    int r = res;
    for (j = 0; j < 4; j++) {
      if (r == 2) {
        if (bjx > j) {
          bjx = j;
          bj = i + bi + 1;
          break;
        }
      }
      r = mult (r, total);
    }
  }
  if (bjx == 10) {
    printf ("NO\n");
    //fprintf (stderr, "bjx = %d\n", bjx);
    return;
  }

  int total_len = 1 + bix + bjx;
  if (bj >= l) {
    total_len ++;
  }
  
  if (total_len > x) {
    printf ("NO\n");
    //fprintf (stderr, "total_len = %d (bix = %d, bjx = %d bi = %d bj = %d)\n", total_len, bix, bjx, bi, bj);
    return;
  }
  
  printf ("YES\n");
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
