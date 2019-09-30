#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int w;
	int l;
} path_t;

path_t paths[1010];

int cmp(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}

int main(void)
{
	int t, ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int x, s, r, n, i, j;
		double t;
		double ret = 0;
		scanf("%d %d %d %lf %d", &x, &s, &r, &t, &n);
		j = x;
		r -= s;
		for (i = 0; i < n; i++) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			paths[i].w = w+s;
			paths[i].l = b-a;
			x -= paths[i].l;
		}
		paths[n].l = x;
		paths[n].w = s;
		qsort(paths, n+1, 2*sizeof(int), cmp);
		for (i = 0; i <= n; i++) {
			double runtime = (double)paths[i].l/(paths[i].w+r);
			if (runtime <= t) {
				t -= runtime;
				ret += runtime;
			} else {
				double l = (double)paths[i].l - (paths[i].w+r)*t;
				ret += t;
				ret += l/paths[i].w;
				t = 0;
			}
		}
		printf("Case #%d: %.8lf\n", ti, ret);
	}
	return 0;
}