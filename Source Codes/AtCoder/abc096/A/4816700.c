#include <stdio.h>
int main()
{
	int a=0,b=0;
	scanf("%d %d",&a,&b);
	if(a<=b)
	{
		printf("%d",a);
	}
	else
	{
		printf("%d",a-1);
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^