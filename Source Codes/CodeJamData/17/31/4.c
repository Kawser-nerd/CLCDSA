#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, K;
struct pancake {
	int R;
	int H;
} RH[1000];

int cmp(const void* x, const void* y) {
	const struct pancake* a = (const struct pancake*)x;
	const struct pancake* b = (const struct pancake*)y;
	long long a_score = (long long)a->R * a->H;
	long long b_score = (long long)b->R * b->H;
	if (a_score < b_score) return 1;
	if (a_score > b_score) return -1;
	return 0;
}

int main(void) {
	int T, case_count;
	double pi = 4.0 * atan(1);
	if (scanf("%d", &T) != 1) return 1;
	for (case_count = 1; case_count <= T; case_count++) {
		int i, j;
		long long max_score = 0;
		if (scanf("%d%d", &N, &K) != 2) return 1;
		for (i = 0; i < N; i++) {
			if (scanf("%d%d", &RH[i].R, &RH[i].H) != 2) return 1;
		}
		qsort(RH, N, sizeof(*RH), cmp);
		for (i = 0; i < N; i++) {
			int count = 1;
			long long current_score = (long long)RH[i].R * RH[i].H;
			int max_R = RH[i].R;
			for (j = 0; j < N && count < K; j++) {
				if (i != j && RH[i].R >= RH[j].R) {
					count++;
					current_score += (long long)RH[j].R * RH[j].H;
					if (RH[j].R > max_R) max_R = RH[j].R;
				}
			}
			if (count == K) {
				current_score = current_score * 2 + (long long)max_R * max_R;
				if (current_score > max_score) max_score = current_score;
			}
		}
		printf("Case #%d: %.15f\n", case_count, pi * (double)max_score);
	}
	return 0;
}
