#include <stdio.h>

#define int long long

signed main(){
	int N, A, B, C, D, i;
	scanf("%lld%lld%lld%lld%lld", &N, &A, &B, &C, &D);
	for(i = 0; i < N; i++){
		if(i * C - (N - 1 - i) * D <= B - A && B - A <= i * D - (N - 1 - i) * C){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld", &N, &A, &B, &C, &D);
  ^