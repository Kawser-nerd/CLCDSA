#include <stdio.h>
#include <stdlib.h>
struct node {
	int f;
	int t;
	int sp;
}a[3000], b[2000];
int tn, ti, i, n, m, s, r, x;
double res, t, k;
int cmp(const void *cmps, const void *cmpt)
{
	struct node *x = cmps, *y = cmpt;
	return x->sp < y->sp ? -1 : 1;
}
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%d%d%d%lf%d", &x, &s, &r, &t, &n);	
		for (i = 0; i < n; ++i)
			scanf("%d%d%d", &a[i].f, &a[i].t, &a[i].sp);
		for (i = m = 0; i < n; ++i)
			if (!i && a[i].f || i && a[i].f > a[i - 1].t) {
				if (i)
					b[m].f = a[i - 1].t;
				else
					b[m].f = 0;
				b[m].t = a[i].f;
				b[m++].sp = 0;
			}
		if (a[n - 1].t < x) {
			b[m].f = a[n - 1].t;
			b[m].t = x;
			b[m++].sp = 0;
		}
		for (i = 0; i < m; ++i)
			a[n++] = b[i];
		qsort(a, n, sizeof(a[0]), cmp);
		for (res = i = 0; i < n; ++i)
			if (t > 0 && r > s) {
				if (t * (r + a[i].sp) >= a[i].t - a[i].f) {
					k = (double)(a[i].t - a[i].f) / (r + a[i].sp);
					t -= k;
					res += k;
				} else {
					res += (double)(a[i].t - a[i].f - t * (r + a[i].sp)) / (s + a[i].sp) + t;
					t = -1;
				}
			} else
				res += (double)(a[i].t - a[i].f) / (s + a[i].sp);
		printf("%.6lf\n", res);
	}
	return 0;
}
