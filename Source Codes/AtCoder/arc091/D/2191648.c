#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	return a <= b ? a : b;
}

int grundy(int X, int K){
	if(X < K){
		return 0;
	}
	else if(X % K == 0){
		return X / K;
	}
	else{
		int fl = X / K;
		int t = (X - K * fl) / (fl + 1);
		return grundy(min(X - fl - 1, X - t * (fl + 1)), K);
	}
}

int main(){
	int N, A, K, i, g = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &A, &K);
		g ^= grundy(A, K);
	}
	if(g == 0){
		printf("Aoki\n");
	}
	else{
		printf("Takahashi\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A, &K);
   ^