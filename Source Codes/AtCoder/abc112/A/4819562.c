#include<stdio.h>
int main(void){
	int N,A,B;
	scanf("%d",&N);
	if(N==1){
		printf("Hello World");
	}else if(N==2){
		scanf("%d%d",&A,&B);
		printf("%d",A+B);
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&A,&B);
   ^