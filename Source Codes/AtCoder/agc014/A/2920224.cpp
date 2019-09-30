#include<stdio.h>
int main()
{
	int i,n;
	int s[1000];
	int a,b,c,d;
	int x,y,z;
	scanf("%d %d %d",&a,&b,&c);
	for(i=0;i<100;i++)
	{
		if(a%2==0&&b%2==0&&c%2==0)
		{
			x=a/2;
			y=b/2;
			z=c/2;
			a=y+z;
			b=x+z;
			c=x+y;
			
			
			
		}
		
		else break;
		
		
	}
	
	n=i;
	if(n==100) printf("-1");
	else printf("%d",n);
	return 0;
	
	
	
	
}