#include <stdio.h>
#include <assert.h>

#define MAXN 10001
int x[MAXN];
int b[MAXN];
int c[MAXN];
int r[MAXN];

int main () {
  int __;
  scanf ("%d", &__);
  int _;
  for (_ = 0; _ < __; _ ++) {
    printf ("Case #%d:", _ + 1);
    int n, i, j;
    scanf ("%d", &n);
    for (i = 0; i < n - 1; i++) {
      scanf ("%d", &x[i]);      
      x[i] --;
    }
    b[n - 1] = 0;
    c[0] = n - 1;
    int cc = 1;
    int ok = 1;
    for (i = n - 2; i >= 0; i--) {
      int ii = -1;
      for (j = 0; j < cc; j ++) if (c[j] == x[i]) {
        ii = j;
        break;
      }
      if (ii == -1) {
        ok = 0;
        break;
      }
      int min = -10000;
      int max = 10000;
      if (ii > 0) {
        assert (x[c[ii]] == c[ii - 1]);
      }
      min = b[c[ii]];
      if (ii < cc - 1) {
        assert (x[c[ii + 1]] == c[ii]);        
        max = b[c[ii + 1]];
      }
      for (j = i + 1; j < n; j++) {
        if (b[j] > min) {
          b[j] ++;
        }
      }
      assert (min < max);
      b[i] = min + 1;
      c[ii + 1] = i;
      cc = ii + 2;
    }
    if (ok) {
      r[n - 1] = 999999999;
      for (i = n - 2; i >= 0; i--) {
        r[i] = r[x[i]] - b[i] * (x[i] - i);
      }
      for (i = 0; i < n; i++) {
        printf (" %d", r[i]);
      }
    } else {
      printf (" Impossible");
    }
    printf ("\n");
  }
  return 0;
}
