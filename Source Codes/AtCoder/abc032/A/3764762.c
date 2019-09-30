#include<stdio.h>
int A, B, N;
int main(){
	scanf("%d%d%d", &A, &B, &N);
	while(1){
		if(N%A==0 && N%B==0){break;}
		N++;
	}
	printf("%d\n", N);
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A, &B, &N);
  ^