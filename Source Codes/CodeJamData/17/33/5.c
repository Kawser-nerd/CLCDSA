#include <stdio.h>
#include <stdlib.h>

int read_data(void) {
	int a, b;
	if (scanf("%d.%d", &a, &b) != 2) exit(1);
	return a * 10000 + b;
}

int main(void) {
	int T, case_count;
	if (scanf("%d", &T) != 1) return 1;
	for (case_count = 1; case_count <= T; case_count++) {
		int N, K;
		int P;
		int U[50];
		int i;
		int current_U[50];
		if (scanf("%d%d", &N, &K) != 2) return 1;
		P = read_data();
		for (i = 0; i < N; i++) {
			current_U[i] = U[i] = read_data();
		}
		if (N != K) {
			printf("Case #%d: large\n", case_count);
		} else {
			int left = P;
			int best, second;
			int best_data[50];
			int best_count;
			double answer;
			while (left > 0) {
				best = second = 10000;
				best_count = 0;
				for (i = 0; i < N; i++) {
					if (best > current_U[i]) {
						second = best;
						best = current_U[i];
						best_data[0] = i;
						best_count = 1;
					} else if (best == current_U[i]) {
						best_data[best_count++] = i;
					} else if (second > current_U[i]) {
						second = current_U[i];
					}
				}
				if ((second - best) * best_count <= left) {
					for (i = 0; i < best_count; i++) {
						current_U[best_data[i]] += second - best;
					}
					left -= (second - best) * best_count;
				} else {
					for (i = 0; i < best_count; i++) {
						current_U[best_data[i]] += left / best_count;
					}
					left -= (left / best_count) * best_count;
					for (i = 0; i < best_count && i < left; i++) {
						current_U[best_data[i]]++;
					}
					left = 0;
				}
			}
			answer = 1.0;
			for (i = 0; i < N; i++) {
				answer *= current_U[i] / 10000.0;
			}
			printf("Case #%d: %.15g\n", case_count, answer);
		}
	}
	return 0;
}
