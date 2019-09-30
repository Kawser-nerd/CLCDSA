#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int ti, tn, a[60][60], i, j, k;
int64_t b, m;

int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d: ", ti);
		fscanf(stdin, "%" PRId64 "%" PRId64, &b, &m);
		if (m > ((int64_t)1 << (b - 2))) {
			fprintf(stdout, "IMPOSSIBLE\n");
			continue;
		}
		fprintf(stdout, "POSSIBLE\n");
		memset(a, 0, sizeof(a));
		if (m == ((int64_t)1 << (b - 2))) {
			a[0][b - 1] = 1;
			--m;
		}
		for (i = b - 3; i >= 0; --i) {
			if (m & ((int64_t)1 << i)) {
				a[0][b - i - 2] = 1;
				for (j = b - i - 2; j < b; ++j)
					for (k = j + 1; k < b; ++k)
						a[j][k] = 1;
				m -= ((int64_t)1 << i);
			}
		}
		for (i = 0; i < b; ++i) {
			for (j = 0; j < b; ++j)
				fprintf(stdout, "%d", a[i][j]);
			fprintf(stdout, "\n");
		}
	}
}

