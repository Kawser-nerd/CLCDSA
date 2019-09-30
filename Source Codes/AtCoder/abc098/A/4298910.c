#include <stdio.h>
#include <string.h>

int main(void)
{
	int a,b,max;
	scanf("%d%d",&a,&b);
	max=a+b;
	if(max<a-b){max=a-b;}
	if(max<a*b){max=a*b;}
	printf("%d\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^