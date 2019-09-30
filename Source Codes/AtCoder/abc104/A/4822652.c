#include<stdio.h>
int main(void){
	int R;
	scanf("%d",&R);
	if(R<1200){
		printf("ABC");
	}else if((1200<=R)&&(R<2800)){
		printf("ARC");
	}else{
		printf("AGC");
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&R);
  ^