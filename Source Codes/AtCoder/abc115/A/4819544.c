#include<stdio.h>
int main(void){
	int D;
	scanf("%d",&D);
	if(D==25){
		printf("Christmas");
	}else if(D==24){
		printf("Christmas Eve");
	}else if(D==23){
		printf("Christmas Eve Eve");
	}else if(D==22){
		printf("Christmas Eve Eve Eve");
	}
return 0;
} ./Main.c: In function �main�:
./Main.c:4:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&D);
  ^