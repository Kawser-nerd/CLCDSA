#include <stdio.h>
int main(void){
	int c,a;
	scanf("%d%d",&c,&a);
	printf("%d\n",c*a/2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&c,&a);
  ^