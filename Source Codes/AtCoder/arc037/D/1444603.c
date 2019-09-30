#include <stdio.h>

#define ll long long
#define p (ll)(1e9 + 7)

ll MOD(ll a){
	if(a >= 0) return a % p;
	return p + a % p;
}

int main(){
	ll L, k, s, t, K, S, T;
	scanf("%lld", &L);
	for(k = 1, s = 2, t = 1; L > 0; L--, k = K, s = S, t = T){
		K = MOD(3 * k + MOD(s * MOD(s * s)));
		S = MOD(s * MOD(s + s * s - t * t));
		T = MOD(t * MOD(s * s - t * t));
	}
	printf("%lld\n", K);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &L);
  ^