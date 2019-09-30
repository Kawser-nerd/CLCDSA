#include <stdio.h>

#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
	int i;
	int t, c;

	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		int d, n;
		double max_sec;

		scanf("%d %d", &d, &n);

		max_sec = 0;
		for (i = 0; i < n; i++) {
			int k, s;
			scanf("%d %d", &k, &s);
			max_sec = max(max_sec, (double)(d - k) / s);
		}

		printf("Case #%d: %.10f\n", c, d / max_sec);
	}

	return 0;
}
