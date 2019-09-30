#include <stdio.h>
#include <stdlib.h>
#define int long long

int N, K, *A;

int max(int a, int b){
//	printf("(a, b) = (%lld, %lld)\n", a, b);
	return a >= b ? a : b;
}

int only_one_dig_sum(int d, int b){
	int i, ans = 0;
	for(i = 0; i < N; i++){
		ans += ((b << d) ^ (A[i] & ((int)1 << d)));
	}
//	printf("ans[%lld][%lld] = %lld\n", d, b, ans);
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
//	printf("d = %lld\n", d);
	if(d < 0){
		return 0;
	}
	else if((((int)1 << d) & K) == 0){
//		printf("test3\n");
		return only_one_dig_sum(d, 0) + solve(d - 1);
	}
	else{
//		printf("test4\n");
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
//	printf("solve(%lld) = %lld\n", (int)2, solve(2));
//	printf("solve(%lld) = %lld\n", (int)1, solve(1));
//	printf("solve(%lld) = %lld\n", (int)0, solve(0));
	printf("%lld\n", solve(50));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^
./Main.c:50:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^