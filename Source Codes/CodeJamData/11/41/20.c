#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int b;
     int e;
     int w;
} walkways;

int cmp(const void *a, const void *b)
{
     return ((walkways *)a)->w - ((walkways *)b)->w;
}

int main()
{
     int T, x, s, r, t, n, i, j;

     scanf("%d", &T);

     for (i = 0; i < T; i++) {
	  walkways w[1000];
	  int p = 0;
	  double sum = 0, res;

	  scanf("%d %d %d %d %d", &x, &s, &r, &t, &n);

	  for (j = 0; j < n; j++) {
	       scanf("%d %d %d", &w[j].b, &w[j].e, &w[j].w);

	       p += w[j].e - w[j].b;
	  }

	  p = x - p;
	  res = t;

	  qsort(w, n, sizeof(walkways), cmp);

	  if (r * res <= p) {
	       sum += res;
	       p -= r * res;
	       res = 0;
	       sum += (double)p / s;
	  } else {
	       sum += (double)p / r;
	       res -= sum;
	  }

	  for (j = 0; j < n; j++) {
	       if (res > 0) {
		    if ((w[j].w + r) * res <= w[j].e - w[j].b) {
			 sum += res + (double)(w[j].e - w[j].b - (w[j].w + r) * res) / (s + w[j].w);
			 res = 0;
		    } else {
			 double tmp = (double)(w[j].e - w[j].b) / (w[j].w + r);
			 sum += tmp;
			 res -= tmp;
		    }
	       } else {
		    sum += (double)(w[j].e - w[j].b) / (w[j].w + s);
	       }
	  }

	  printf("Case #%d: %lf\n", i + 1, sum);
     }

     return 0;
}
