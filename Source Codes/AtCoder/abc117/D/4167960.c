#include <stdio.h>
#include <stdlib.h>
#define int long long

int N, K, *A;

int max(int a, int b){
	return a >= b ? a : b;
}

int only_one_dig_sum(int d, int b){
	int i, ans = 0;
	for(i = 0; i < N; i++){
		ans += ((b << d) ^ (A[i] & ((int)1 << d)));
	}
	return ans;
}

int solve_sub(int d){
	if(d < 0){
		return 0;
	}
	else{
		return max(only_one_dig_sum(d, 0), only_one_dig_sum(d, 1)) + solve_sub(d - 1);
	}
}

int solve(int d){
	if(d < 0){
		return 0;
	}
	else if((((int)1 << d) & K) == 0){
		return only_one_dig_sum(d, 0) + solve(d - 1);
	}
	else{
		return max(only_one_dig_sum(d, 1) + solve(d - 1), only_one_dig_sum(d, 0) + solve_sub(d - 1));
	}
}

signed main(){
	int i;
	scanf("%lld%lld", &N, &K);
	A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	printf("%lld\n", solve(50));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^