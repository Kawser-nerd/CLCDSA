#include <stdio.h>
int main(void){
	int d;
	scanf("%d",&d);
	if(d==25)printf("Christmas");
	if(d==24)printf("Christmas Eve");
	if(d==23)printf("Christmas Eve Eve");
	if(d==22)printf("Christmas Eve Eve Eve");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&d);
  ^