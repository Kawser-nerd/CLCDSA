#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p 998244353

int *fact, *fact_inv;

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

int comb(int N, int k){
	return MOD(fact[N] * MOD(fact_inv[k] * fact_inv[N - k]));
}

signed main(){
	int N, A, B, K, i, j, ans = 0;
	scanf("%lld%lld%lld%lld", &N, &A, &B, &K);
	fact = (int *)malloc(sizeof(int) * (N + 1));
	fact_inv = (int *)malloc(sizeof(int) * (N + 1));
	fact[0] = 1;
	fact_inv[0] = 1;
	for(i = 1; i <= N; i++){
		fact[i] = MOD(fact[i - 1] * i);
		fact_inv[i] = power(fact[i], p - 2);
	}
	for(i = 0; i <= N; i++){
		if((K - i * A) % B == 0){
			j = (K - i * A) / B;
			if(j >= 0 && j <= N){
				ans = MOD(ans + comb(N, i) * comb(N, j));
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld", &N, &A, &B, &K);
  ^