#include <stdio.h>

int a[100][100];

int main ()
{
  int i, t, j, k, n, m, l, h;
  scanf ("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf ("%d%d", &n, &m);
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++) scanf ("%d", &a[j][k]);
    }
    for (j = 0; j < n; j++) {
      h = 0;
      for (k = 0; k < m; k++) {
        if (h < a[j][k]) h = a[j][k];
      }
      for (k = 0; k < m; k++) {
        if (h > a[j][k]) {
          for (l = 0; l < n && a[j][k] >= a[l][k]; l++) {}
          //if (l < n) printf ("%d %d is wrong h=%d, %d < %d | %d %d\n",
          //  j, k, h, a[j][k], a[l][k], l, k);
          if (l < n) break; //printf ("%d %d is wrong\n", j, k);
        }
      }
      if (k < m) break;
    }
    //printf ("%d %d ", n, m);
    printf ("Case #%d: %s\n", i, j < n ? "NO" : "YES");
  }
  return 0;
}
