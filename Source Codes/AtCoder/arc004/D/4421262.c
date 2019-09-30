#include <stdio.h>
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

int comb(int N, int k){
	if(k == 0){
		return 1;
	}
	else{
		return MOD(MOD(N * inverse(k)) * comb(N - 1, k - 1));
	}
}

signed main(){
	int N, M, i, j, ans;
	scanf("%lld%lld", &N, &M);
	if(N < 0){
		N = -N;
	}
	ans = power(2, M - 1);
	for(i = 2; i * i <= N; i++){
		for(j = 0; N % i == 0; j++, N /= i);
		ans = MOD(ans * comb(M - 1 + j, j));
	}
	if(N > 1){
		ans = MOD(ans * M);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^