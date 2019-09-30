#include<stdio.h>
int main(void)
{
	int d;
	scanf("%d",&d);
	if(d==25){
		printf("Christmas\n");
	}
	else if(d==24){
		printf("Christmas Eve\n");
	}
	else if(d==23){
		printf("Christmas Eve Eve\n");
	}
	else{
		printf("Christmas Eve Eve Eve\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&d);
  ^