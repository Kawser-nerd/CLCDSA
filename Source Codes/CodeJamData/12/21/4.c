#include <stdio.h>

#define EPS (1e-10)
#define ABS(d) ((d) < 0 ? -(d) : (d))
#define ZERO(d) (ABS((d)) < EPS)

int main() {
	int ntc, tc;
	scanf("%d", &ntc);
	int i, j, k;

	int N, X;
	int s[1000];
	for (tc = 1; tc <= ntc; tc++) {
		scanf("%d", &N);
		X = 0;
		for (i = 0; i < N; i++) {
			scanf("%d", &s[i]);
			X += s[i];
		}

		printf("Case #%d:", tc);
		for (i = 0; i < N; i++) {
			double miny = 0, maxy = 1;
			while (!ZERO(miny - maxy)) {
				double share = (miny + maxy) / 2;
				double Z = s[i] + X * share;
				double remaining = 1 - share;
				for (j = 0; j < N; j++) {
					if (i == j) continue;
					if (s[j] >= Z) continue;
					double need = (Z - s[j]) / X;
					if (need > remaining) break;
					remaining -= need;
				}
				if (j == N) {
					miny = share;
				} else {
					maxy = share;
				}
			}
			printf(" %.8lf", miny * 100);
		}
		printf("\n");
	}
	return 0;
}

