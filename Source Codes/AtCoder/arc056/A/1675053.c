#include <stdio.h>
#include <stdlib.h>
#define int long long

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

signed main(){
	int A, B, K, L;
	scanf("%lld%lld%lld%lld", &A, &B, &K, &L);
	printf("%lld\n", min(B * (K / L) + A * (K % L), B * (K / L) + B));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld", &A, &B, &K, &L);
  ^