#include<stdio.h>
int main(void){
	int A,B;
	scanf("%d%d",&A,&B);
	if(((A*B)%2)==1){
		printf("Yes");
	}else{
		printf("No");
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&A,&B);
  ^