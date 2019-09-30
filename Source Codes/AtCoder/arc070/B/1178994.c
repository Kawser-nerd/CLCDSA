#include <stdio.h>
#include <stdlib.h>

int comp(const void *p1, const void *p2) {
	return *(const int *)p1 - *(const int*)p2;
}
int needs(int);

int N, K, a[5010];
int dp[5010][5010];

int main(void) {
	int i, left, right, center;
	
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		// ?????????????
		if (a[i] >= K) {
			N--;
			i--;
		}
	}
	qsort(a, N, sizeof(int), comp);
	
	// ?????????
	left = 0; right = N - 1;
	while (left <= right) {
		center = (left + right) / 2;
		if (needs(center))
			right =  center - 1;
		else
			left = center + 1;
	}

	printf("%d\n", left);
	return 0;
}

int needs(int index) {
	int i, j;

	// ?????????????
	for (j = 0; j < K; j++) {
		dp[0][j] = 0;
		dp[index][j] = 0;	
	}
	if (index != 0) dp[0][a[0]] = 1;
	dp[0][0] = 1;

	for (i = 1; i < N; i++) {
		for (j = 0; j < K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (i != index && j - a[i] >= 0)
				dp[i][j] |= dp[i - 1][j - a[i]];
		}
	}

	for (j = K - a[index]; j < K; j++) {
		if (dp[N - 1][j] == 1)
			return 1;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^