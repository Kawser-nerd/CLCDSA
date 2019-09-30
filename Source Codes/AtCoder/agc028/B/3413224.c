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

signed main(){
	int N, i, ans = 0;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	int *fact = (int *)malloc(sizeof(int) * (N + 1));
	int *inv = (int *)malloc(sizeof(int) * (N + 1));
	int *inv_sum = (int *)malloc(sizeof(int) * (N + 1));
	fact[0] = 1;
	inv_sum[0] = 0;
	for(i = 1; i <= N; i++){
		fact[i] = MOD(fact[i - 1] * i);
		inv[i] = inverse(i);
		inv_sum[i] = MOD(inv_sum[i - 1] + inv[i]);
	}
	for(i = 0; i < N; i++){
		ans = MOD(ans + (inv_sum[i + 1] + inv_sum[N - i] - 1) * A[i]);
	}
	printf("%lld\n", MOD(ans * fact[N]));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^