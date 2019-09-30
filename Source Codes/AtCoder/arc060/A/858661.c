#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long dp[60][60][2510];

int main() {
	int A, i, j, k, N, x[60];
	long long C;
	scanf("%d%d", &N, &A);
	for (i=0;i<N;i++) scanf("%d", &x[i]);

	dp[0][0][0] = 1;
	for (k=1;k<2510;k++) dp[0][0][k] = 0;
	for (i=0;i<N;i++) {
		for (j=0;j<=i+1;j++) {
			for (k=0;k<2510;k++) {
				if (k < x[i]) dp[i+1][j][k] = dp[i][j][k];
				else if (k >= x[i] && j >= 1) dp[i+1][j][k] = dp[i][j][k] + dp[i][j-1][k-x[i]];
				else dp[i+1][j][k] = 0;
			}
		}
	}

	C = 0;
	for (k=1;k<=N;k++) C += dp[N][k][k*A];
	printf("%lld\n", C);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &A);
  ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i=0;i<N;i++) scanf("%d", &x[i]);
                    ^