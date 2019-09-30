#include <stdio.h>

static int p[300];

int main(void)
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int n, x = 0, i, j;
		double l, r, f;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", p+i);
			x += p[i];
		}
		printf("Case #%d:", ti);
		for (i = 0; i < n; i++) {
			l = 0;
			r = 1;
			while (l+1e-10 < r) {
				double need = 0, s;
				f = (l+r)/2;
				s = p[i]+f*x;
				for (j = 0; j < n; j++) {
					double need1;
					if (i == j) continue;
					need1 = s-p[j];
					if (need1 > 0) need += need1;
				}
				if (need > (1-f)*x) r = f;
				else l = f;
			}
			printf(" %.7lf", 100.0*l);
		}
		printf("\n");
	}
	return 0;
}
