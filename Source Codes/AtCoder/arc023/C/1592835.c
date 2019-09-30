#include <stdio.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	if(a >= 0){
		return a % p;
	}
	else{
		return p + a % p;
	}
}

int power(int a, int n){
	if(n == 0){
		return 1;
	}
	else if(n % 2 == 0){
		return power(MOD(a * a), n / 2);
	}
	else{
		return MOD(a * power(a, n - 1));
	}
}

int inverse(int a){
	return power(a, p - 2);
}

int comb(int n, int k){
	int numerator, denominator;
	for(numerator = 1, denominator = 1; k > 0; n--, k--){
		numerator = MOD(numerator * n);
		denominator = MOD(denominator * k);
	}
	return MOD(numerator * inverse(denominator));
}

signed main(){
	int N, A, lastA, i, ans = 1, unknown = 0;
	scanf("%lld", &N);
	scanf("%lld", &lastA);
	for(i = 1; i < N; i++){
		scanf("%lld", &A);
		if(A == -1){
			unknown++;
		}
		else{
			if(unknown > 0){
				ans = MOD(ans * comb(A - lastA + unknown, unknown));
				unknown = 0;
			}
			lastA = A;
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &lastA);
  ^
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A);
   ^