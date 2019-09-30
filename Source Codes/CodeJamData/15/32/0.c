#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

void solve (void) {
  int k, l, s;
  static char kb[1000], ws[1000];
  assert (scanf ("%d %d %d\n", &k, &l, &s) == 3);
  assert (scanf ("%s\n", kb) == 1);
  assert (scanf ("%s\n", ws) == 1);
  assert (strlen (kb) == (size_t)k);
  assert (strlen (ws) == (size_t)l);

  if (l > s) {
    printf ("0.0\n");
    return;
  }

  int i, j, x;
  for (i = 0; i < l; i++) {
    int ok = 0;
    for (j = 0; j < k; j++) {
      if (ws[i] == kb[j]) {
        ok = 1;
        break;
      }
    }
    if (!ok) {
      printf ("0.0\n");
      return;
    }
  }

  int overlap = l;
  for (i = 1; i < l; i++) {
    if (!memcmp (ws, ws + i, l - i)) {
      overlap = i;
      break;
    }
  }
  int count = 1 + (s - l) / overlap;

  static double q[200][200];
  bzero (q, sizeof (q));
  for (i = 0; i < l; i++) {
    for (j = 0; j < k; j++) {
      for (x = i; x >= 0; x --) {
        if (!memcmp (ws, ws + (i - x), x) && ws[x] == kb[j]) {
          break;
        }
      }
      x ++;
      q[i][x] += 1.0/k;
    }
  }

//  for (i = 0; i < l; i++)
 //   for (j = 0; j <= l; j++) {
   //   fprintf (stderr, "%d %d %lf\n", i, j, q[i][j]);
    //}

  double res = 0;
  static double p[200][200];
  bzero (p, sizeof (p));
  p[0][0] = 1;
  for (i = 0; i < s; i++) {
    for (j = 0; j < l; j++) {
      if (p[i][j]) {
        for (x = 0; x <= l; x++) {
          if (q[j][x]) {
            int r = x;
            if (r == l) {
              res += p[i][j] * q[j][x];
              r = (l - overlap);
            }
            p[i + 1][r] += q[j][x] * p[i][j];
          }
        }
      }
    }
  }
  printf ("%lf\n", count - res);
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
