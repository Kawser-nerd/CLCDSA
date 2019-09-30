#include<stdio.h>
int main()
{
	int T=1,X,Y,Z,i,t,sort[3];
	//scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d%d",&X,&Y,&Z);
		if(X>Y)
		{
			t=X;
			X=Y;
			Y=t;
		}
		if(Y>Z)
		{
			t=Y;
			Y=Z;
			Z=t;
		}
		if(X>Y)
		{
			t=X;
			X=Y;
			Y=t;
		}
		if((Z-X)%2==0 && (Z-Y)%2==0)
		{
			printf("%d\n",(Z-X)/2+(Z-Y)/2);
		}
		else if((Z-X)%2==1 && (Z-Y)%2==0 || (Z-X)%2==0 && (Z-Y)%2==1)
		{
			printf("%d\n",(Z-Y)/2+(Z-X)/2+2);
		}
		else
		{
			printf("%d\n",(Z-Y)/2+(Z-X)/2+1);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&X,&Y,&Z);
   ^