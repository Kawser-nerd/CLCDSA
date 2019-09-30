#include <stdio.h>
#include <string.h>

int ti, tn, i, s, n, x, y, a[30];

int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d:", ti);
		fscanf(stdin, "%d", &n);
		memset(a, 0, sizeof(a));
		for (i = s = 0; i < n; ++i) {
			fscanf(stdin, "%d", &a[i]);
			s += a[i];
		}
		while (s > 0) {
			for (x = i = 0; i < 26; ++i) {
				if (a[i] && a[i] > a[x]) {
					x = i;
				}
			}
			--a[x];
			--s;
			for (y = i = 0; i < 26; ++i) {
				if (a[i] && a[i] > a[y]) {
					y = i;
				}
			}
			if (a[y]) {
				--a[y];
				--s;
				for (i = 0; i < 26; ++i)
					if (a[i] > (s >> 1)) {
						break;
					}
				if (i == 26) {
					fprintf(stdout, " %c%c", 'A' + x, 'A' + y);
				} else {
					fprintf(stdout, " %c", 'A' + x);
					++a[y];
					++s;
				}
			} else {
				fprintf(stdout, " %c", 'A' + x);
			}
		}
		fprintf(stdout, "\n");
	}
}

