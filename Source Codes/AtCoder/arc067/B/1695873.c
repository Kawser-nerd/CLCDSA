#include<stdio.h>
typedef long long ll;

int main(){
	ll n, a, b, old, now;
	scanf("%lld%lld%lld%lld", &n, &a, &b, &old);
	ll ans = 0;
	for(int i = 1; i < n; ++i){
		scanf("%lld", &now);
		ans += (a * (now - old) > b ? b : a * (now - old));
		old = now;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld", &n, &a, &b, &old);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &now);
   ^