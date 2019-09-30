#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int *fact, *fact_inv;

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int A(int N, int x){
	if(N - x < 0 || N - x > x - 1 || x - 1 < 0){
		return 0;
	}
	else{
		return MOD(MOD(fact[x - 1] * fact_inv[N - x]) * MOD(fact[x] * fact_inv[2 * x - N - 1]));
	}
}

signed main(){
	int N, i, ans = 0;
	scanf("%lld", &N);
	fact = (int *)malloc(sizeof(int) * (N + 1));
	fact_inv = (int *)malloc(sizeof(int) * (N + 1));
	fact[0] = 1;
	fact_inv[0] = 1;
	fact_inv[1] = 1;
	for(i = 1; i <= N; i++){
		fact[i] = MOD(fact[i - 1] * i);
	}
	for(i = 2; i <= N; i++){
		fact_inv[i] = MOD(-(p / i) * fact_inv[p % i]);
	}
	for(i = 1; i <= N; i++){
		fact_inv[i] = MOD(fact_inv[i] * fact_inv[i - 1]);
	}
	for(i = 1; i < N; i++){
		ans = MOD(ans + i * MOD(MOD(fact[N - 1 - i] * A(N - 1, i)) - MOD(fact[N - i] * A(N - 1, i - 1))));
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^