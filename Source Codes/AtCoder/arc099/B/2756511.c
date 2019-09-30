#include <stdio.h>
#include <stdlib.h>
#define int long long

int S(int a){
	int ans = 0;
	while(a > 0){
		ans += a % 10;
		a /= 10;
	}
	return ans;
}

int min(int a, int b){
	if(a * S(b) <= b * S(a)){
		return a;
	}
	else{
		return b;
	}
}

int f(int N){
	int i, j, d, lO, ans = N;
	for(i = 0, lO = 1; i < 16; i++, lO *= 10){
		d = (N / lO) % 10;
		for(j = 1; d + j <= 10; j++){
			ans = min(ans, ((N / lO) + j) * lO - 1);
		}
	}
	return ans;
}

signed main(){
	int K, N = 1, i;
	scanf("%lld", &K);
	for(i = 0; i < K; i++){
		printf("%lld\n", N);
		N = f(N + 1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &K);
  ^