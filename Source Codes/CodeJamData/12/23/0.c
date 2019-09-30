#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
int a[MAXN];
int b[2 * (1 << 20)];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );

}

int main () {
  int __;
  scanf ("%d", &__);
  int a[MAXN];
  int _;
  for (_ = 0; _ < __; _ ++) {
    printf ("Case #%d:\n", _ + 1);
    int n;
    scanf ("%d", &n);
    int i, j;
    for (i = 0; i < n; i++) {
      scanf ("%d", &a[i]);
    }
    for (i = 0; i < (1 << n); i++) {
      int s = 0;
      for (j = 0; j < n; j++) if (i & (1 << j)) {
        s += a[j];
      }
      b[2 * i] = s;
      b[2 * i + 1] = i;
    }
    qsort (b, i, 8, compare);
    int ok = 0;
    for (i = 0; i < (1 << n) - 1; i ++) if (b[2 * i] == b[2 * i + 2]) {
      ok = 1;
      for (j = 0; j < n; j++) if (b[2 * i + 1] & (1 << j)) {
        printf ("%d ", a[j]);
      }
      printf ("\n");
      for (j = 0; j < n; j++) if (b[2 * i + 3] & (1 << j)) {
        printf ("%d ", a[j]);
      }
      printf ("\n");
      break;
    }
    if (!ok) {
      printf ("Impossible\n");
    }
    
  }
  return 0;
}
