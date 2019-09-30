#include <stdio.h>
#include <stdlib.h>

typedef struct {
     double d;
     int n;
} dist;

int cmp(const void *a, const void *b)
{
     if (((dist *)a)->d < ((dist *)b)->d) {
	  return 1;
     } else if (((dist *)a)->d == ((dist *)b)->d) {
	  return 0;
     } else {
	  return -1;
     }
}

int main()
{
     int T, l, n, c, i, j;
     long long t;
     dist a[1001];

     scanf("%d", &T);

     for (i = 0; i < T; i++) {
	  double p = 0;
	  int f = 0;

	  scanf("%d %lld %d %d", &l, &t, &n, &c);

	  for (j = 0; j < c; j++) {
	       int x;

	       scanf("%d", &x);

	       a[j].d = (double)x;
	       a[j].n = n / c;

	       if (j < n % c) a[j].n++;
	  }

	  for (j = 0; j < c; j++) {
	       if (a[j].n == 0) {
		    printf("Case #%d: %lld\n", i + 1, (long long)p);
		    f = 1; break;
	       }

	       if (p + a[j].d *2 <= t) {
		    p += a[j].d * 2;
		    a[j].n--;
	       } else {
		    a[c].d = a[j].d - (t - p) / 2.0;
		    a[c].n = 1;
		    a[j].n--;
		    p = t;;
		    c++;
		    break;
	       }

	       if (j == c - 1) j = -1;
	  }

	  if (f == 0) {
	       qsort(a, c, sizeof(dist), cmp);

	       for (j = 0; j < c; j++) {
		    if (a[j].n == 0) continue;

		    if (l >= a[j].n) {
			 p += a[j].n * a[j].d;
			 l -= a[j].n;
		    } else {
			 p += l * a[j].d;
			 p += (a[j].n - l) * a[j].d * 2;
			 l = 0;
		    }
	       }

	       printf("Case #%d: %lld\n", i + 1, (long long)p);
	  }
     }

     return 0;
}
