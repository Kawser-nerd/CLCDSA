#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p 1000000007

int *fact, *fact_inv;

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int combination(int n, int k){
	if(n < 0 || k < 0 || n < k){
		return 0;
	}
	else{
		return MOD(fact[n] * MOD(fact_inv[k] * fact_inv[n - k]));
	}
}

signed main(){
	int R, C, X, Y, D, L, i, j, k, l;
	scanf("%lld%lld%lld%lld%lld%lld", &R, &C, &X, &Y, &D, &L);
	fact = (int *)malloc(sizeof(int) * (X * Y + 1));
	fact[0] = 1;
	for(i = 1; i <= X * Y; i++){
		fact[i] = MOD(fact[i - 1] * i);
	}
	fact_inv = (int *)malloc(sizeof(int) * (X * Y + 1));
	fact_inv[0] = 1;
	fact_inv[1] = 1;
	for(i = 2; i <= X * Y; i++){
		fact_inv[i] = MOD(-(p / i) * fact_inv[p % i]);
	}
	for(i = 1; i <= X * Y; i++){
		fact_inv[i] = MOD(fact_inv[i - 1] * fact_inv[i]);
	}
	for(i = 0; i <= X * Y; i++){
	}
	int **dp = (int **)malloc(sizeof(int *) * (X + 1));
	for(i = 0; i <= X; i++){
		dp[i] = (int *)malloc(sizeof(int) * (Y + 1));
		for(j = 0; j <= Y; j++){
			dp[i][j] = 0;
		}
	}
	for(i = 1; i <= X; i++){
		for(j = 1; j <= Y; j++){
			dp[i][j] = combination(i * j, D + L);
			for(k = 0; k <= i; k++){
				for(l = 0; l <= j; l++){
					if(k == i && l == j){
						continue;
					}
					dp[i][j] = MOD(dp[i][j] - dp[k][l] * (i - k + 1) * (j - l + 1));
				}
			}
		}
	}
/*	for(i = 0; i <= X; i++){
		for(j = 0; j <= Y; j++){
			printf("dp[%lld][%lld] = %lld\n", i, j, dp[i][j]);
		}
	}
*/	printf("%lld\n", MOD((R - X + 1) * (C - Y + 1) * MOD(dp[X][Y] * combination(D + L, D))));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld%lld", &R, &C, &X, &Y, &D, &L);
  ^