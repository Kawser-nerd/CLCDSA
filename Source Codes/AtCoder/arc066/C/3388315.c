#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, i, j;
	char sub[2];
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	int *op = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		if(i == 0){
			op[i] = 1;
		}
		else{
			scanf("%s", sub);
			op[i] = (sub[0] == '+' ? 1 : -1);
		}
		scanf("%lld", &A[i]);
	}
	int **dp = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		dp[i] = (int *)malloc(sizeof(int) * 3);
		for(j = 0; j < 3; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = A[0];
	for(i = 1; i < N; i++){
		if(op[i] == 1){
			dp[i][0] = max(max(dp[i - 1][0] + A[i], dp[i - 1][1] - A[i]), dp[i - 1][2] + A[i]);
			dp[i][1] = max(dp[i - 1][1] - A[i], dp[i - 1][2] + A[i]);
			dp[i][2] = dp[i - 1][2] + A[i];
		}
		else{
			dp[i][0] = max(max(dp[i - 1][0] - A[i], dp[i - 1][1] + A[i]), dp[i - 1][2] - A[i]);
			dp[i][1] = max(max(dp[i - 1][1] + A[i], dp[i - 1][2] - A[i]), dp[i - 1][0] - A[i]);
			dp[i][2] = max(dp[i - 1][2] - A[i], dp[i - 1][1] + A[i]);
		}
	}
	printf("%lld\n", dp[N - 1][0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:21:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s", sub);
    ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^