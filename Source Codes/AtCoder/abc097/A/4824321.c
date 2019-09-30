#include <stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0;
	int tmp1=0,tmp2=0,tmp3=0;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	tmp1=a-b;
	if(tmp1<0)
	{
		tmp1=-tmp1;
	}
	
	tmp2=b-c;
	if(tmp2<0)
	{
		tmp2=-tmp2;
	}
	
	tmp3=a-c;
	
	if(tmp3<0)
	{
		tmp3=-tmp3;
	}
	
	
	
	if(tmp1<=d)
	{
		if(tmp2<=d)
		{
			printf("Yes");
		}
	
		else if(tmp3<=d)
		{
			printf("Yes");
		}
		
		else
		{
			if(tmp3<=d)
			{
				printf("Yes");
			}
			
			else
			{
				printf("No");
			}
			
		}
	}
	
	else
	{
		if(tmp3<=d)
		{
			printf("Yes");
		}
		
		else
		{
			printf("No");
		}
	}
		
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&a,&b,&c,&d);
  ^