#include <stdio.h>
#include <inttypes.h>

int ti, tn;
int64_t k, c, s, t, i, j, p;

int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d:", ti);
		fscanf(stdin, "%" PRId64 "%" PRId64 "%" PRId64, &k, &c, &s);
		t = (k + c - 1) / c;
		if (s < t) {
			fprintf(stdout, " IMPOSSIBLE\n");
		} else {
			for (i = 0; i < k; ) {
				for (j = 0, p = 0; j < c && i < k; ++j, ++i) {
					p = p * k + i;
				}
				fprintf(stdout, " %" PRId64, p + 1);
			}
			fprintf(stdout, "\n");
		}
	}
	return 0;
}

