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

int comb(int n, int k){
	if(k == 0){
		return 1;
	}
	else{
		return MOD(MOD(n * inverse(k)) * comb(n - 1, k - 1));
	}
}

signed main(){
	int N, M, i, j, ans = 1;
	scanf("%lld%lld", &N, &M);
	for(i = 2; M > 1; i++){
		for(j = 0; M % i == 0; j++, M /= i){}
		ans = MOD(ans * comb(j + N - 1, j));
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^