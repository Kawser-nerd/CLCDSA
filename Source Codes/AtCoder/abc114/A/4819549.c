#include<stdio.h>
int main(void){
	int X;
	scanf("%d",&X);
	if(X==7){
		printf("YES");
	}else if(X==5){
		printf("YES");
	}else if(X==3){
		printf("YES");
	}else{
		printf("NO");
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&X);
  ^