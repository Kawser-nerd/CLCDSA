#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

signed main(){
	int N, k, i, j, maxD = 0;
	scanf("%lld", &N);
	int *D = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &D[i]);
		if(D[i] > maxD){
			maxD = D[i];
		}
	}
	int *Dnum = (int *)malloc(sizeof(int) * (maxD + 1));
	for(i = 0; i <= maxD; i++){
		Dnum[i] = 0;
	}
	for(i = 0; i < N; i++){
		Dnum[D[i]]++;
	}
	int **dp = (int **)malloc(sizeof(int *) * 5);
	for(k = 0; k <= 4; k++){
		dp[k] = (int *)malloc(sizeof(int) * (maxD + 1));
		for(i = 0; i <= maxD; i++){
			dp[k][i] = 0;
		}
	}
	for(i = 0; i <= maxD; i++){
		dp[0][i] = 1;
	}
	for(k = 1; k <= 4; k++){
		for(i = 1; i <= maxD; i++){
			dp[k][i] = (dp[k][i - 1] + Dnum[i] * dp[k - 1][i / 2]) % p;
		}
	}
/*	for(k = 0; k <= 4; k++){
		for(i = 0; i <= maxD; i++){
			printf("%lld  ", dp[k][i]);
		}
		printf("\n");
	}
*/	printf("%lld\n", dp[4][maxD]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &D[i]);
   ^