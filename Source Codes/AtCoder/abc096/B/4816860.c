#include <stdio.h>
int main()
{
	int a=0,b=0,c=0,k=0;
	int total=0;
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d",&k);
	
	for(int i=0;i<k;i++)
	{
	if(a>b)
	{
		if(a>c)
		{
			a=2*a;
		}
		else
		{
			c=2*c;
		}
	}
	
	else
	{
		if(b>c)
		{
			b=2*b;
		}
		
		else
		{
			c=2*c;
		}
	}
	}
	
	total=a+b+c;
	printf("%d",total);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&k);
  ^