#include <stdio.h>

#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	return a % p;
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
	int W, H, ans = 1, n, k;
	scanf("%lld%lld", &W, &H);
	W--;
	H--;
	for(n = H + 1, k = 1; k <= W; n++, k++){
		ans = MOD(MOD(ans * n) * inverse(k));
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &W, &H);
  ^