#include <stdio.h>

int main(void)
{
int n,a,b;
scanf("%d%d%d",&n,&a,&b);
if(n*a <= b)
	{printf("%d",n*a);}
if(n*a > b)
	{printf("%d",b);}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d",&n,&a,&b);
 ^