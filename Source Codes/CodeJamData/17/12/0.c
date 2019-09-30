#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int grams[55];
int ingredientPackages[55][55];
int ingpair[55][55][2];
int size[55];

int max(int a, int b)
{
	return a > b ? a : b;
}

int cmp(const void* a, const void* b)
{
	const int* ta = (const int*) a;
	const int* tb = (const int*) b;
	if (ta[0] != tb[0]) return ta[0] - tb[0];
	return ta[1] - tb[1];
}

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	int TK = 0;
	while (T--) {
		int N = 0;
		int P = 0;
		scanf("%d %d", &N, &P);
		memset(size, 0, sizeof(size));
		for (int i = 0;i < N;i++) scanf("%d", &grams[i]);
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < P;j++) {
				scanf("%d", &ingredientPackages[i][j]);
				// 9 * grams[i] * a <= 10*x <= 11 * grams[i] * b, a <= b
				int rr = (10*ingredientPackages[i][j]) / (9*grams[i]);
				int ll = (10*ingredientPackages[i][j] + 11 * grams[i] - 1) / (11 * grams[i]);
				if (ll == 0) ll = 1;
				// if (ll < 10) {
				// 	fprintf(stderr, "ll = %d, rr = %d\n", ll, rr);
				// 	for (int t = ll;t <= 10;t++) {
				// 		if (9 * grams[i] * t <= 10 * ingredientPackages[i][j] && 10 * ingredientPackages[i][j] <= 11 * grams[i] * t) {
				// 			fprintf(stderr, "valid %d\n", t);
				// 		}
				// 	}
				// }
				if (ll <= rr) {
					ingpair[i][size[i]][0] = ll;
					ingpair[i][size[i]++][1] = rr;
				}
			}
			qsort(ingpair[i], size[i], sizeof(ingpair[i][0]), cmp);
		}
		int ans = 0;
		int pos[55] = {0};
		while (1) {
			int maxv = 0;
			int bye = 0;
			for (int i = 0;i < N;i++) {
				if (pos[i] >= size[i]) {
					bye = 1;
					break;
				}
				maxv = max(maxv, ingpair[i][pos[i]][0]);
			}
			if (bye) break;
			int ok = 1;
			for (int i = 0;i < N;i++) {
				if (maxv > ingpair[i][pos[i]][1]) {
					ok = 0;
					pos[i]++;
				}
			}
			if (ok) {
				ans++;
				for (int i = 0;i < N;i++) pos[i]++;
			}
		}
		printf("Case #%d: %d\n", ++TK, ans);
	}
	return 0;
}
