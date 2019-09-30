#include<stdio.h>
int min(int a,int b)
{
	if(a<b)
	a=a;
	if(a>b)
	a=b;
	return a;
}
int max(int a,int b )
{
	if(a>b)
	a=a;
	if(a<b)
	a=b;
	return a;
}
int main()
{
	int a,b,c,d;
	int sum;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (b<c||d<a)
	sum = 0;
	else
	{
		sum=min(b,d)-max(a,c);
	}
		printf("%d\n",sum);
	return 0;
}