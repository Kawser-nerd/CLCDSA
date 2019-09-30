#include <stdio.h>
#define int long long
#define M (int)(2 * 1e12)

signed main(){
	int A, K, ans;
	scanf("%lld%lld", &A, &K);
	if(K == 0){
		ans = M - A;
	}
	else{
		for(ans = 0; A < M; A += 1 + K * A, ans++){}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &A, &K);
  ^