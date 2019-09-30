#include <stdio.h>

int main(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x=a+b,y=b+c,z=c+a;
	if(x <= y && x <= z)
		{printf("%d",x);}
	else if( y <= x && y <= z)
		{printf("%d",y);}
	else
		{printf("%d",z);}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^