#include <stdio.h>

double max(double x, double y) {
	if (x>y) return x;
	else return y;
}

int main() {
	int i, j, K, N;
	scanf("%d%d", &N, &K);

	double dp[N+1][K+1][2], p;
	for (j=K;j>=0;j--) {
		dp[N][j][1] = 1.0;
		dp[N][j][0] = 0.0;
	}
	for (i=N-1;i>=0;i--) {
		p = 1.0/(i+1);
		dp[i][K][1] = dp[i+1][K][1]*(1-p) + dp[i+1][K][0]*p;
		dp[i][K][0] = dp[i+1][K][0];
		for (j=K-1;j>=0;j--) {
			dp[i][j][1] = dp[i+1][j][1]*(1-p) + p*max(dp[i+1][j+1][1],dp[i+1][j][0]);
			dp[i][j][0] = dp[i+1][j][0]*(1-p) + p*max(dp[i+1][j+1][1],dp[i+1][j][0]);
		}
	}

	printf("%.10lf\n", dp[0][0][0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^