#include<stdio.h>

int main(){
	int A, D;
	scanf("%d %d", &A, &D);

	if(A >= D){
		printf("%d\n", A*(D+1));
	} else {
		printf("%d\n", (A+1)*D);
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &A, &D);
  ^