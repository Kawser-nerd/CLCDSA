#include <stdio.h>
#include <string.h>

int ti, tn, i, n, j, k, a[40], b[40], cnt;

int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d:\n", ti);
		fscanf(stdin, "%d%d", &n, &j);
		memset(a, 0, sizeof(a));
		a[0] = a[n - 1] = 1;
		for (i = 0; i < n; ++i)
			fprintf(stdout, "%d", a[i]);
		for (i = 2; i <= 10; ++i)
			fprintf(stdout, " %d", i + 1);
		fprintf(stdout, "\n");
		for (i = cnt = 1; cnt < j; ++i) {
			memset(b, 0, sizeof(b));
			for (k = 0; k < i; ++k)
				b[k] = (k << 1) + 1;
			while (1) {
				memset(a, 0, sizeof(a));
				a[0] = a[n - 1] = 1;
				for (k = 0; k < i; ++k)
					a[b[k]] = a[b[k] + 1] = 1;
				for (k = 0; k < n; ++k)
					fprintf(stdout, "%d", a[k]);
				for (k = 2; k <= 10; ++k)
					fprintf(stdout, " %d", k + 1);
				fprintf(stdout, "\n");
				if (++cnt >= j) {
					break;
				}
				if (b[0] == n - 1 - (i << 1)) {
					break;
				}
				for (k = i - 1; k >= 0 && b[k] == n - 1 - ((i - k) << 1); --k);
				if (k < 0) {
					break;
				}
				++b[k];
				for (k++; k < i; ++k) {
					b[k] = b[k - 1] + 2;
				}
			}
		}
	}
}

