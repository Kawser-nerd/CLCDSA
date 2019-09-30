#include <stdio.h>

double dp[1005][1005][2];

double max(double a, double b);

int main() {

	int N,K;

	scanf("%d %d",&N,&K);

	int i, j, k;

	for (i = 0; i <= K; i++) {
		dp[N][i][0] = 0;
		dp[N][i][1] = 1.0;
	}

	for (i = N - 1; i >= 0; i--) {
		for (j = 0; j <= K; j++) {
			for (k = 0; k < 2; k++) {
				double P = 1.0 / (i + 1.0);
				double tmp = (1.0 - P)*dp[i + 1][j][k] + P*max(dp[i + 1][j + 1][1], dp[i + 1][j][0]);
				dp[i][j][k] = tmp;
			}
		}
	}
	printf("%.9lf\n",dp[0][0][0]);


	return 0;
}
double max(double a, double b) {
	if (a >= b) { return a; }
	else { return b; }
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&K);
  ^