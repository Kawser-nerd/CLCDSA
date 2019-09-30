#include <stdio.h>
#define MOD 1000000007

int main(void) {
	int n,m;
	long long int ans;
	
	scanf("%d %d",&n,&m);
	
	if (n > m) {
		n ^= m ^= n ^= m;
	}
	
	if (m -n > 1) {
		ans = 0;
	} else {
		ans = 1;
		for (int i = 1;i <= n;i++) {
			ans *= i;
			ans %= MOD;
			ans *= i;
			ans %= MOD;
		}
		
		if (n == m) {
			ans *= 2;
			ans %= MOD;
		} else {
			ans *= m;
			ans %= MOD;
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^