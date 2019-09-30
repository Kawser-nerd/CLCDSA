#include <stdio.h>

int main(){
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	if(A > B || A >= N){
		printf("Takahashi\n");
	}
	else if(A < B){
		printf("Aoki\n");
	}
	else if(N % (A + 1) == 0){
		printf("Aoki\n");
	}
	else{
		printf("Takahashi\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &A, &B);
  ^