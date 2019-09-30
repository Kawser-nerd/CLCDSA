#include <stdio.h>

int main(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a == b)
		{printf("%d\n",c);}
	if(a == c)
		{printf("%d\n",b);}
	if(b == c)
		{printf("%d\n",a);}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^