#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

int inverse(int a){
	return power(a, p - 2);
}

int main(){
	int N, Q, i, j;
	scanf("%lld%lld", &N, &Q);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	int **dp = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		dp[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			if(A[i] > A[j]){
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	int q, X, Y, inv2 = inverse(2);
	int *subOX = (int *)malloc(sizeof(int) * N);
	int *subOY = (int *)malloc(sizeof(int) * N);
	int *subXO = (int *)malloc(sizeof(int) * N);
	int *subYO = (int *)malloc(sizeof(int) * N);
	int subXY, subYX;
	for(q = 0; q < Q; q++){
		scanf("%lld%lld", &X, &Y);
		X--;
		Y--;
		for(i = 0; i < N; i++){
			subOX[i] = dp[i][X];
			subOY[i] = dp[i][Y];
			subXO[i] = dp[X][i];
			subYO[i] = dp[Y][i];
		}
		subXY = dp[X][Y];
		subYX = dp[Y][X];
		for(i = 0; i < N; i++){
			if(i != X && i != Y){
				dp[i][X] = MOD((subOX[i] + subOY[i]) * inv2);
				dp[i][Y] = MOD((subOX[i] + subOY[i]) * inv2);
				dp[X][i] = MOD((subXO[i] + subYO[i]) * inv2);
				dp[Y][i] = MOD((subXO[i] + subYO[i]) * inv2);
			}
		}
		dp[X][Y] = MOD((subXY + subYX) * inv2);
		dp[Y][X] = MOD((subXY + subYX) * inv2);
/*		printf("dp[%lld]:\n", q);
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				printf("%lld ", dp[i][j]);
			}
			printf("\n");
		}
		printf("\n");
*/	}
	int ans = 0;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(i < j){
				ans = MOD(ans + dp[i][j]);
			}
		}
	}
	ans = MOD(ans * power(2, Q));
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &Q);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^
./Main.c:53:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &X, &Y);
   ^