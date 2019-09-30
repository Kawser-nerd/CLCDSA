#include <stdio.h>
#define MAXN 1000
int a[MAXN];
int b[MAXN];
int main () {
  int __;
  scanf ("%d", &__);
  int a[MAXN];
  int _;
  for (_ = 0; _ < __; _ ++) {
    printf ("Case #%d:", _ + 1);
    int n;
    scanf ("%d", &n);
    int i;
    int s = 0;
    for (i = 0; i < n; i++) {
      scanf ("%d", &a[i]);
      b[i] = a[i];
      s += a[i];
    }
    int j;
    for (i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) if (b[i] > b[j]) {
        int t = b[i]; b[i] = b[j]; b[j] = t;
      }
    for (i = 0; i < n; i++) {
      double l = 0;
      double r = 1;
      while (r - l > 1e-10) {
        double p = (r + l) / 2;
        double z = p;
        for (j = 0; j < n; j++) if (i != j) {
          double q = ((a[i] - a[j]) * 1.0 + s * p) / s;
          if (q < 0) {
            q = 0;
          }
          z += q;
          if (z >= 1) {
            break;
          }
        }
        if (z < 1) {
          l = p;
        } else {
          r = p;
        }
      }
      printf (" %lf", l * 100);

    }
    printf ("\n");
  }
  return 0;
}
