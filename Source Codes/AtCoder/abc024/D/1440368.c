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

signed main(){
	int A, B, C;
	scanf("%lld", &A);
	scanf("%lld", &B);
	scanf("%lld", &C);
	int denom = inverse(MOD(A * (B + C) - B * C));
	printf("%lld %lld\n", MOD(MOD(C * (B - A)) * denom), MOD(MOD(B * (C - A)) * denom));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &A);
  ^
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &B);
  ^
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &C);
  ^