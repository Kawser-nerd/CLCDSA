#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int x,y,t,i,r;
int main()
{
	freopen("text.in","r",stdin);
	freopen("text.out","w",stdout);
	scanf("%d",&t);
	for (r=1;r<=t;r++)
	{
		printf("Case #%d: ",r);
		scanf("%d %d",&x,&y);
		if (x>0)
		for (i=0;i<x;i++)
		{
			printf("WE");
		}
		if (x<0)
		{
		x=-x;
		for (i=0;i<x;i++)
		{
			printf("EW");
		}
		}
		if (y>0)
		for (i=0;i<y;i++)
		{
			printf("SN");
		}
		if (y<0)
		{
		y=-y;
		for (i=0;i<y;i++)
		{
			printf("NS");
		}		
		}
		printf("\n");
	}
	return 0;
}
