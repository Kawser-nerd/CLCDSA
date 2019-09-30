#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int M, N;
int valid[1<<16];
long long dp[1<<16];

int contain(int i, int j) {
	return ((i & (1<<j)) != 0);
}

int main() {
	int i, j;
	scanf("%d%d", &N, &M);
	int x[M], y[M];
	for (i=0;i<M;i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--; y[i]--;
	}

	for (i=0;i<(1<<N);i++) {
		valid[i] = 1;
		for (j=0;j<M;j++) {
			if (contain(i,y[j]) && !contain(i,x[j])) valid[i] = 0;
		}
	}

	dp[0] = 1;
	for (i=1;i<(1<<N);i++) {
		if (valid[i]) {
			for (j=0;j<N;j++) { if (contain(i,j) && valid[i^(1<<j)]) dp[i] += dp[i^(1<<j)]; }
		}
	}

	printf("%lld\n", dp[(1<<N)-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x[i], &y[i]);
   ^