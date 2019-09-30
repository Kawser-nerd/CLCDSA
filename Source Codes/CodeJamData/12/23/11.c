#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ti, tn, i, j, k, n, s, a[50], b[50], can[2000001], from[2000001], lastmax, fir;
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d:\n", ti);
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (i = 1; i < (1 << n); ++i) {
			for (j = s = b[0] = 0; j < n; ++j) {
				if (i & (1 << j))
					s += a[j];
				else
					b[++b[0]] = a[j];
			}
			memset(can, 0, sizeof(can));
			can[lastmax = 0] = 1;
			for (j = 1; j <= b[0]; ++j) {
				for (k = lastmax; k >= 0; --k)
					if (can[k]) {
						can[k + b[j]] = 1;
						from[k + b[j]] = k;
						if (k + b[j] == s)
							break;
					}
				if (k >= 0)
					break;
				lastmax += b[j];
			}
			if (j <= b[0]) {
				for (k = 0, fir = 1; k < n; ++k)
					if (i & (1 << k)) {
						if (!fir)
							putchar(' ');
						else
							fir = 0;
						printf("%d", a[k]);
					}
				putchar('\n');
				for (fir = 1; s; s = from[s]) {
					if (!fir)
						putchar(' ');
					else
						fir = 0;
					printf("%d", s - from[s]);
				}
				putchar('\n');
				break;
			}
		}
		if (i == (1 << n))
			printf("Impossible\n");
	}
	return 0;
}
