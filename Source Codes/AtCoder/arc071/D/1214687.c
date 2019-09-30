#include <stdio.h>
#include <stdlib.h>
#define p (int)(1e9 + 7)

long long int mod(long long int x){
	if(x < 0){
		return p + x % p;
	}
	else{
		return x % p;
	}
}

int main(){
	long long int n;
	scanf("%lld", &n);
	long long int *A = (long long int *)malloc(sizeof(long long int) * (n + 1));
	long long int *sum = (long long int *)malloc(sizeof(long long int) * (n + 1));
	A[0] = 1;
	A[1] = n;
	sum[1] = n;
	int i;
	for(i = 2; i <= n; i++){
		A[i] = mod(n * (n - 1) + 3 - i + sum[i - 1] - A[i - 2]);
		sum[i] = mod(sum[i - 1] + A[i]);
	}
	printf("%lld\n", A[n]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^