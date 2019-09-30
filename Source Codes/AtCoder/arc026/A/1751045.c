#include<stdio.h>
int main(void){
	int N,A,B;
	scanf("%d %d %d",&N,&A,&B);
	if(N>5){
		printf("%d\n",5*B+(N-5)*A);
	}
	else{
		printf("%d\n",N*B);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&N,&A,&B);
  ^