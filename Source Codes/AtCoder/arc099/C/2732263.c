#include <stdio.h>
#include <stdlib.h>

int cmp(const void* x, const void* y) {
	int a = *(const int*)x;
	int b = *(const int*)y;
	if (a < b) return -1;
	return a > b;
}

int N, M;
int next_num[1024];
int next[1024][1024];

int inv_num[1024];
int inv[1024][1024];
int group[1024];

int count_count;
int count[1024][2];

int ayaneru(int node, int g) {
	int i, ng = (g == 1 ? 2 : 1);
	if (group[node] != 0) {
		/* ?????????????????? ? ?? */
		return group[node] == g;
	}
	group[node] = g;
	count[count_count][g - 1]++;
	for (i = 0; i < inv_num[node]; i++) {
		if (!ayaneru(inv[node][i], ng)) return 0;
	}
	return 1;
}

int memo[1024][1024];

int kitaeri(int cpos, int acc) {
	int c1, c2;

	if (cpos >= count_count) return acc;
	if (memo[cpos][acc]) return ~memo[cpos][acc];

	c1 = kitaeri(cpos + 1, acc + count[cpos][0]);
	c2 = kitaeri(cpos + 1, acc + count[cpos][1]);

	return ~(memo[cpos][acc] = ~((abs(c1 - (N / 2)) <= abs(c2 - (N / 2))) ? c1 : c2));
}

int main(void) {
	int i;
	int hayamin;
	if (scanf("%d%d", &N, &M) != 2) return 1;
	for (i = 0; i < M; i++) {
		int A, B;
		if (scanf("%d%d", &A, &B) != 2) return 1;
		A--;
		B--;
		next[A][next_num[A]++] = B;
		next[B][next_num[B]++] = A;
	}
	for (i = 0; i < N; i++) {
		qsort(next[i], next_num[i], sizeof(next[i][0]), cmp);
	}
	/* ??????? = ????????? */
	for (i = 0; i < N; i++) {
		int j, ptr = 0;
		for (j = 0; j < N; j++) {
			if (i == j) continue;
			else if (ptr < next_num[i] && j == next[i][ptr]) {
				ptr++;
			} else {
				inv[i][inv_num[i]++] = j;
			}
		}
	}
	for (i = 0; i < N; i++) {
		if (group[i] == 0) {
			if (!ayaneru(i, 1)) {
				puts("-1");
				return 0;
			}
			count_count++;
		}
	}
#if 0
	/* test */
	for (i = 0; i < count_count; i++) {
		printf("%10d %10d\n", count[i][0], count[i][1]);
	}
#endif
	hayamin = kitaeri(0, 0);
	printf("%d\n", hayamin * (hayamin - 1) / 2 + (N - hayamin) * (N - hayamin - 1) / 2);
	return 0;
}