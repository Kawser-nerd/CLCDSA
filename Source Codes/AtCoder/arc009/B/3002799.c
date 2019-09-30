#include <stdio.h>
#include <stdlib.h>

int B[10], B_inv[10];

int comversion(int x){
	int ans = 0, i;
	for(i = 1; i <= x; i *= 10){
		ans += i * B_inv[(x / i) % 10];
	}
	return ans;
}

int compare(const void *a, const void *b){
	return comversion(*(int *)a) - comversion(*(int *)b);
}

int main(){
	int N, i;
	for(i = 0; i < 10; i++){
		scanf("%d", &B[i]);
		B_inv[B[i]] = i;
	}
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), compare);
	for(i = 0; i < N; i++){
		printf("%d\n", A[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &B[i]);
   ^
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^