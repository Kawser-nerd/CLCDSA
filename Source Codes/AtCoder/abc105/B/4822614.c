#include<stdio.h>
int main(void){
	int N;
	scanf("%d",&N);
	if((N==1)||(N==2)||(N==3)||(N==5)||(N==6)||(N==9)||(N==10)||(N==13)||(N==17)){
		printf("No");
	}else{
		printf("Yes");
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^