#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int T, N, K;
struct { double side; int H, R; } pancakes[1000];

static inline int comp(const void *a, const void *b) {
	return *(double *)a < *(double *)b ? 1 : *(double *)a > *(double *)b ? -1 : 0;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &K);
		for (int n = 0; n < N; n++) {
			scanf("%d %d", &pancakes[n].R, &pancakes[n].H);
			pancakes[n].side = 2.0 * pancakes[n].R * pancakes[n].H;
		}
		qsort(pancakes, N, sizeof(*pancakes), comp);
		
		double best = 0.0;
		for (int base = 0; base < N; base++) {
			double area = pancakes[base].side + (double)pancakes[base].R * pancakes[base].R;
			int k = 1;
			for (int n = 0; n < N && k < K; n++) {
				if (n != base && pancakes[n].R <= pancakes[base].R)
					area += pancakes[n].side, k++;
			}
			if (k == K)
				best = area > best ? area : best;
		}
		printf("Case #%d: %.9lf\n", t, best * M_PI);
	}
	return 0;
}
