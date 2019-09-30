#include <stdio.h>

int main(void)
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a+b==c+d)
		{printf("Balanced");}
	else if(a+b>c+d)
		{printf("Left");}
	else
		{printf("Right");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ^