#include <stdio.h>
#include <string.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
int ti, tn, i, j, k, n, e, r, res;
int a[20][20], v[20];

int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fscanf(stdin, "%d%d%d", &e, &r, &n);
		for (i = 0; i < n; ++i)
			fscanf(stdin, "%d", &v[i]);
		memset(a, 0, sizeof(a));
		res = 0;
		for (j = 0; j <= e; ++j) {
			a[0][MIN(j + r, e)] = MAX(a[0][MIN(j + r, e)], (e - j) * v[0]);
			res = MAX(res, a[0][MIN(j + r, e)]);
		}
		for (i = 1; i < n; ++i)
			for (j = 0; j <= e; ++j)
				for (k = 0; k <= j; ++k) {
					a[i][MIN(k + r, e)] = MAX(a[i][MIN(k + r, e)], a[i - 1][j] + (j - k) * v[i]);
					res = MAX(res, a[i][MIN(k + r, e)]);
				}
		fprintf(stdout, "Case #%d: %d\n", ti, res);
	}
	return 0;
}
