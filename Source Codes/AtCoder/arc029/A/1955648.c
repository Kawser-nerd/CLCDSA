#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, i, j, ans = 1000, A, B;
	scanf("%d", &N);
	int *t = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &t[i]);
	}
	for(i = 0; i < (1 << N); i++){
		A = 0;
		B = 0;
		for(j = 0; j < N; j++){
			if((i & (1 << j)) == 0){
				A += t[j];
			}
			else{
				B += t[j];
			}
		}
		ans = min(ans, max(A, B));
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &t[i]);
   ^