#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

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

int gcd(int x, int y){
	if(y == 0){
		return x;
	}
	else{
		return gcd(y, x % y);
	}
}

signed main(){
	int N, i, gcdL = 0, minL = p;
	scanf("%lld", &N);
	int *L = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &L[i]);
		if(L[i] < minL){
			minL = L[i];
		}
	}
	for(i = 0; i < N; i++){
		gcdL = gcd(gcdL, L[i] - minL);
	}
	printf("%lld\n", power(2, minL + (gcdL + 1) / 2));
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &L[i]);
   ^