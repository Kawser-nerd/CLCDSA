#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int n=1000;
	int f=0;
	int sum=0;
	while(n--)
	{
		if(a%2!=0||b%2!=0||c%2!=0)
		{f=1;
		break;
		}
		else
		{   int x,y,z;
		    x=a;
		    y=b;
		    z=c;
			a=(y/2)+(z/2);
			b=(x/2)+(z/2);
			c=(x/2)+(y/2);
			sum++;
		}
	}
	if(f==1)
	printf("%d\n",sum);
	else
	printf("-1\n");
	
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^