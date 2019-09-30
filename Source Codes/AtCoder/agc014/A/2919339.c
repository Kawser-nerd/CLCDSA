#include<stdio.h>

int main()
{
	int A,B,C;
	int a,b,c;
	while(scanf("%d%d%d",&A,&B,&C)!=EOF)
	{
		int t=1000;
		int q=0;
		while(t--)
		{
			if(A%2==1 || B%2==1 || C%2==1) break;
			a=A/2;
			b=B/2;
			c=C/2;
			A=b+c;
			B=a+c;
			C=a+b;
			q++;		
		}
		if(t>0) printf("%d\n",q);
		else printf("-1\n");	
	}
	
	
	
}