#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007LL

long long dp[410][410]={{0}};
long long prod[410][410]={{0}};

int main() {
	int C, i, j, k, N;
	int A[410], B[410];
	long long p;
	scanf("%d%d", &N, &C);
	for (i=0;i<N;i++) {
		scanf("%d", &A[i]);
	}
	for (i=0;i<N;i++) {
		scanf("%d", &B[i]);
	}

	for (i=0;i<N;i++) {
		for (j=A[i];j<=B[i];j++) {
			p = 1;
			for (k=0;k<=C;k++) {
				prod[i][k] = (prod[i][k] + p) % MOD;
				p = (p*j) % MOD;
			}
		}
	}
	
	dp[0][0] = 1;
	for(i=0;i<N;i++) {
		for (j=0;j<=C;j++) {
			for (k=0;k<=j;k++) {
				dp[i+1][j] = (dp[i+1][j] + dp[i][j-k]*prod[i][k]) % MOD;
			}
		}
	}

	printf("%lld\n", dp[N][C]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &C);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &B[i]);
   ^