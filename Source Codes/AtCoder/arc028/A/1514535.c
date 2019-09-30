#include <stdio.h>

int main(){
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	if((N - 1) % (A + B) < A){
		printf("Ant\n");
	}
	else{
		printf("Bug\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &A, &B);
  ^