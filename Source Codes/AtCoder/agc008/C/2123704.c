#include <stdio.h>
#define int long long

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int aI, aO, aT, aJ, aL, aS, aZ, ans;
	scanf("%lld%lld%lld%lld%lld%lld%lld", &aI, &aO, &aT, &aJ, &aL, &aS, &aZ);
	ans = aO + (aI / 2) * 2 + (aJ / 2) * 2 + (aL / 2) * 2;
	if(aI > 0 && aJ > 0 && aL > 0){
		ans = max(ans, aO + 3 + ((aI - 1) / 2) * 2 + ((aJ - 1) / 2) * 2 + ((aL - 1) / 2) * 2);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld%lld%lld", &aI, &aO, &aT, &aJ, &aL, &aS, &aZ);
  ^