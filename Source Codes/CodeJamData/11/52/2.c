#include "stdio.h"


#define MAXN 10005
int x[MAXN];
int y[MAXN];
/*int doit (int z) {
	int i;
	for (i = 0; i < MAXN; i++) y[i] = 0;
	int ss = 0;
	for (i = 1; i <= MAXN; i++) {
		int t = x[i] - ss;
		if (t < 0) return 0;
		if (t > 0 && z + i - 1 > MAXN) return 0;
		if (t > 0) {
			y[z + i - 1] += t;
		}
		ss += t;
		ss -= y[i];
	}
	return 1;
} */

int doit (void) {	
	int i, j;
	for (i = 0; i < MAXN; i++) y[i] = 0;
	int f = 0;
	int l = 0;
	int worst = 100000;
	for (i = 0; i < MAXN; i++) {
		if (l - f >= x[i]) {
			int j = f;
			while (j + x[i] < l) {
				if (worst > (i - y[j])) {
					worst = (i - y[j]);
				}
				j++;
			}
			f = j;
		} else {
			for (j = l; j < l + x[i] - (l - f); j++) {
				y[j] = i;
			}
			l += x[i] - (l - f);
		}
	}
	return worst;
}

int main () {
	int tn;
	scanf ("%d\n", &tn);
	int tt;
	for (tt = 0; tt < tn; tt++) {
		int n;
		scanf ("%d", &n);
		int i;
		for (i = 0; i < MAXN; i++) x[i] = 0;
		for (i = 0; i < n; i++) {
			int a;
			scanf ("%d", &a);
			x[a] ++;
		}
		int best = 0;
		if (n > 0) {
			/*int l = 1;
			int r = 10001;
			while (r - l > 1) {
				int z = (r + l) >> 1;
				if (doit (z)) l = z;
				else r = z;
			}*/
			best = doit ();
		}
		printf ("Case #%d: ", tt + 1);
		printf ("%d\n", best);
	}
	return 0;
}
