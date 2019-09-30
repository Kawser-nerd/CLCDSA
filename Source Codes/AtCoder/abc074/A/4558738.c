#include<stdio.h>

int main(){

	int N, A, B, C;

	scanf("%d", &N);
	scanf("%d", &A);

	B = N * N;
	C = B - A;

	printf("%d",C);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &A);
  ^