#include <stdio.h>
#include <stdlib.h>
#define int long long

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else{
		return a * power(a, N - 1);
	}
}

int f(int d){
	if(d <= 4){
		return 0;
	}
	else if(d <= 9){
		return 1;
	}
	else{
		return 2;
	}
}

int solve(int A){
	int N, i, A_sub = A;
	int *dig = (int *)malloc(sizeof(int) * 20);
	for(i = 0; A > 0; i++, A /= 10){
		dig[i] = A % 10;
	}
	N = i;
	int *dp = (int *)malloc(sizeof(int) * N);
	dp[0] = f(dig[0]);
	for(i = 1; i < N; i++){
		dp[i] = f(dig[i]) * power(10, i);
		dp[i] += (dig[i] - f(dig[i])) * (power(10, i) - power(8, i));
//		printf("dp[%lld] = %lld\n", i, dp[i]);
		if(dig[i] == 4 || dig[i] == 9){
//			printf("test3\n");
//			printf("A = %lld\n", A_sub);
//			printf("power(10, %lld) = %lld\n", i, power(10, i));
			dp[i] += A_sub % power(10, i);
		}
		else{
			dp[i] += dp[i - 1];
		}
//		printf("dp[%lld] = %lld\n", i, dp[i]);
	}
	return dp[N - 1];
}

signed main(){
	int A, B;
	scanf("%lld%lld", &A, &B);
//	printf("solve(%lld) = %lld\n", B + 1, solve(B + 1));
//	printf("solve(%lld) = %lld\n", A, solve(A));
	printf("%lld\n", solve(B + 1) - solve(A));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:55:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &A, &B);
  ^