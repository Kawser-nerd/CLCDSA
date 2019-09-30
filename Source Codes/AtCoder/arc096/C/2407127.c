#include <stdio.h>
#include <stdlib.h>
#define int long long

int M;

int MOD(int a){
	a %= M;
	return a >= 0 ? a : a + M;
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

signed main(){
	int N, i, j, ans, ways;
	scanf("%lld%lld", &N, &M);
	int *fact = (int *)malloc(sizeof(int) * (N + 1));
	int *fact_inv = (int *)malloc(sizeof(int) * (N + 1));
	int *comb = (int *)malloc(sizeof(int) * (N + 1));
	fact[0] = 1;
	for(i = 1; i <= N; i++){
		fact[i] = MOD(fact[i - 1] * i);
	}
	fact_inv[0] = 1;
	fact_inv[1] = 1;
	for(i = 2; i <= N; i++){
		fact_inv[i] = MOD(-(M / i) * fact_inv[M % i]);
	}
	for(i = 2; i <= N; i++){
		fact_inv[i] = MOD(fact_inv[i - 1] * fact_inv[i]);
	}
/*	for(i = 0; i <= N; i++){
		printf("fact[%lld] = %lld\n", i, fact[i]);
	}
	for(i = 0; i <= N; i++){
		printf("fact_inv[%lld] = %lld\n", i, fact_inv[i]);
	}
*/	for(i = 0; i <= N; i++){
		comb[i] = MOD(fact[N] * MOD(fact_inv[i] * fact_inv[N - i]));
	}
	int **dp = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		dp[i] = (int *)malloc(sizeof(int) * (N + 1));
		dp[i][0] = 1;
	}
	for(j = 1; j <= N; j++){
		dp[0][j] = 0;
	}
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			dp[i][j] = MOD(dp[i - 1][j] + dp[i - 1][j - 1] + j * dp[i - 1][j]);
		}
	}
/*	for(i = 0; i <= N; i++){
		for(j = 0; j <= N; j++){
			printf("dp[%lld][%lld] = %lld  ", i, j, dp[i][j]);
		}
		printf("\n");

	}
*/	int *two_pow_mod_Mm1 = (int *)malloc(sizeof(int) * (N + 1));
	two_pow_mod_Mm1[0] = 1;
	for(i = 1; i <= N; i++){
		two_pow_mod_Mm1[i] = (2 * two_pow_mod_Mm1[i - 1]) % (M - 1);
	}
	for(i = 0, ans = 0; i <= N; i++){
//		printf("i = %lld\n", i);
		for(j = 0, ways = 0; j <= i; j++){
//			printf("j = %lld\n", j);
			ways = MOD(ways + dp[i][j] * power(2, ((N - i) * j + two_pow_mod_Mm1[N - i]) % (M - 1)));
//			printf("ways = %lld\n", ways);
		}
//		printf("ways = %lld\n", ways);
//		printf("comb[%lld] = %lld\n", i, comb[i]);
		ans = MOD(ans + ((i & 1) == 0 ? 1 : -1) * comb[i] * ways);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^