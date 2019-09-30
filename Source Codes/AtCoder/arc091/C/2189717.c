#include <stdio.h>
#include <stdlib.h>
#define int long long

signed main(){
	int N, A, B, k, l, i, j;
	scanf("%lld%lld%lld", &N, &A, &B);
	if(A + B > N + 1 || A * B < N){
		printf("-1\n");
	}
	else if(A == 1){
		for(i = N; i > 0; i--){
			printf("%lld ", i);
		}
		printf("\n");
	}
	else{
		k = (N - B) / (A - 1);
		if((N - B) % (A - 1) == 0){
			l = 0;
		}
		else{
			l = k + N - k * A - B + 1;
		}
//		printf("(k, l) = (%lld, %lld)\n", k, l);
		for(i = 1; i <= k; i++){
			for(j = 1; j <= A; j++){
				printf("%lld ", N - i * A + j);
			}
		}
		for(i = 1; i <= l; i++){
			printf("%lld ", N - k * A - l + i);
		}
		for(i = N - k * A - l; i > 0; i--){
			printf("%lld ", i);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &N, &A, &B);
  ^