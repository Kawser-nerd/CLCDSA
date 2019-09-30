#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, A, i, Amax = 0, f = 0, ans = 1;
	scanf("%lld", &N);
	int *B = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		B[i] = 0;
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &A);
		if(i == 0){
			if(A != 0){
				f = 1;
			}
		}
		Amax = max(Amax, A);
		B[A]++;
	}
	if(f == 1 || B[0] != 1){
		printf("0\n");
		return 0;
	}
	for(i = 0; i < Amax; i++){
		ans = MOD(ans * MOD(power(MOD(power(2, B[i]) - 1), B[i + 1]) * power(2, (B[i + 1] * (B[i + 1] - 1)) / 2)));
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A);
   ^