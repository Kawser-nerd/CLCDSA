#include <stdio.h>
#include <assert.h>

#define MAXN 10001
int a[MAXN];
int x[MAXN], y[MAXN];
int b[MAXN];
int main () {
  int __;
  scanf ("%d", &__);
  int _;
  for (_ = 0; _ < __; _ ++) {
    printf ("Case #%d:", _ + 1);
    int n, i, j;
    scanf ("%d", &n);
    for (i = 0; i < n; i++) {
      scanf ("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
      scanf ("%d", &b[i]);
    }
    for (i = 0; i < n; i++) 
      x[i] = i;
    for (i = 0; i < n; i++)  
      for (j = i + 1; j < n; j++)
        if (a[x[i]] * b[x[j]] > a[x[j]] * b[x[i]] ||
          (a[x[i]] * b[x[j]] == a[x[j]] * b[x[i]] && x[i] > x[j])) {
            int t = x[i]; x[i] = x[j]; x[j] = t;
          }
    for (i = 0; i < n; i++)
      printf (" %d", x[i]);
    printf ("\n");
  }
  return 0;
}
