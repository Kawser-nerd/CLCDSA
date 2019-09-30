#include <stdio.h>
#define int long long
#define p 1777777777

int MOD(int x){
	x %= p;
	return x >= 0 ? x : x + p;
}

int power(int x, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(x * x), N / 2);
	}
	else{
		return MOD(x * power(x, N - 1));
	}
}

int inverse(int x){
	return power(x, p - 2);
}

signed main(){
	int N, K, i, ans = 0, fact = 1;
	scanf("%lld%lld", &N, &K);
	for(i = 2; i <= K; i++){
		fact = MOD(fact * i);
		ans = MOD(ans + (i % 2 == 0 ? 1 : -1) * inverse(fact));
	}
	for(i = 0; i < K; i++){
		ans = MOD(ans * MOD(N - i));
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^