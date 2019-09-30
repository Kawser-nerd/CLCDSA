#include <stdio.h>
int main(void){
	int a,d;
	scanf("%d %d",&a,&d);
	if((a+1)*d>=a*(d+1)) printf("%d\n",(a+1)*d);
	else printf("%d\n",a*(d+1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&d);
  ^