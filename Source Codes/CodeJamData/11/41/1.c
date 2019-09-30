#include "stdio.h"

#define MAXN 1000
#define EPS 1e-10

int main () {
	int tn;
	scanf ("%d\n", &tn);
	int tt;
	int w[MAXN + 1], b[MAXN + 1], e[MAXN + 1], l[MAXN + 1];
	for (tt = 0; tt < tn; tt++) {
		int x, n, s1, s2, ti;
		scanf ("%d%d%d%d%d", &x, &s1, &s2, &ti, &n);
		double t = ti;
		if (s2 < s1) t = 0;
		int i, j;
		for (i = 1; i <= n; i++) {
			scanf ("%d%d%d", &b[i], &e[i], &w[i]);
			l[i] = e[i] - b[i];
			x -= l[i];
		}
		w[0] = 0;
		l[0] = x;
		for (i = 1; i <= n; i++) 
			for (j = i + 1; j <= n; j++) if (w[i] > w[j]){
				int tt;
				tt = l[i]; l[i] = l[j]; l[j] = tt;
				tt = w[i]; w[i] = w[j]; w[j] = tt;
			}
	  double res = 0;
		for (i = 0; i <= n; i++) {
			//fprintf (stderr, "%d %d %d\n", i, l[i], w[i]);
			if (t < EPS) {
				res += l[i] * 1.0/ (w[i] + s1);
			} else {
				double tt = l[i] * 1.0 / (w[i] + s2);
				if (tt <= t + EPS) {
					t -= tt;
					res += tt;
				} else {
					res += t + (l[i] - (w[i] + s2) * t) / (w[i] + s1);
					t = 0;
				}
			}
		}


		printf ("Case #%d: ", tt + 1);
		printf ("%lf\n", res);
	}
	return 0;
}
