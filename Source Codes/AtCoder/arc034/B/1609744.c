#include <stdio.h>
#include <stdlib.h>
#define int long long

int f(int n){
	if(n == 0){
		return 0;
	}
	else{
		return f(n / 10) + n % 10;
	}
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

signed main(){
	int N, i, k;
	scanf("%lld", &N);
	int *ans = (int *)malloc(sizeof(int) * 200);
	for(i = max(1, N - 180), k = 0; i <= N; i++){
		if(i + f(i) == N){
			ans[k] = i;
			k++;
		}
	}
	printf("%lld\n", k);
	for(i = 0; i < k; i++){
		printf("%lld\n", ans[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^