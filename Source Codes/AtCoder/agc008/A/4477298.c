#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	if(y==0)
	{
		if(x<0)
			printf("%d\n",-x);
		else
			printf("%d\n",x+1);
	}
	else if(x==0)
	{
		if(y>0)
			printf("%d",y);
		else
			printf("%d\n",-y+1);
	}
	else if(y>0)
	{
		if(x>0 && x<y)
			printf("%d\n",y-x);
		else if(y<x)
			printf("%d\n",x-y+2);
		else if(-x<y)
			printf("%d\n",y+x+1);
		else
			printf("%d\n",-x-y+1);
	}
	else
	{
		if(x<y)
			printf("%d\n",y-x);
		else if(x<0)
			printf("%d\n",x-y+2);
		else if(x<-y)
			printf("%d\n",-y-x+1);
		else
			printf("%d\n",y+x+1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&x,&y);
  ^