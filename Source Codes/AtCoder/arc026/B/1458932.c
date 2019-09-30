#include <stdio.h>
#define int long long

int power(int a, int n){
	if(n == 0){
		return 1;
	}
	else if(n % 2 == 0){
		return power(a * a, n / 2);
	}
	else{
		return a * power(a, n - 1);
	}
}

signed main(){
	int N, twoN, i, k, sum = 1;
	scanf("%lld", &N);
	twoN = 2 * N;
	for(i = 2; i * i <= N; i++){
		for(k = 0; N % i == 0; k++){
			N /= i;
		}
		sum *= (power(i, k + 1) - 1) / (i - 1);
	}
	if(N > 1){
		sum *= N + 1;
	}
	if(sum == twoN){
		printf("Perfect\n");
	}
	else if(sum < twoN){
		printf("Deficient\n");
	}
	else{
		printf("Abundant\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^