#include <stdio.h>
#include <stdlib.h>
#define int long long

int power(int a, int n){
	if(n == 0){
		return 1;
	}
	else{
		return a * power(a, n - 1);
	}
}

signed main(){
	int N, M;
	scanf("%lld%lld", &N, &M);
	printf("%lld\n", (100 * N + 1800 * M) * power(2, M));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^