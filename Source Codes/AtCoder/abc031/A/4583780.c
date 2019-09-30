#include <stdio.h>
int main(void){
	int a,d;
	scanf("%d%d",&a,&d);
	if(a*(d+1)> (a+1)*d)d++;
	else a++;
	printf("%d\n",a*d);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&d);
  ^