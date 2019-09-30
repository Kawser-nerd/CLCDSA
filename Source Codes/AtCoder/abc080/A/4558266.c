#include<stdio.h>

int main(){

	int  N, A, B, plan1, plan2;

	scanf("%d", &N);
	scanf("%d", &A);
	scanf("%d", &B);

	plan1 = A * N;
	plan2 = B;

	if (plan1 <= plan2) {
		printf("%d", plan1);
	}
	else {
		printf("%d", plan2);
	}
	

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &A);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &B);
  ^