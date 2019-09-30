#include<cstdio>
int main()
{
	int a,sum;
	sum=0;
	scanf("%d",&a);
	while(a>0)
	{
		sum=a+sum;
		a--;}
		printf("%d",sum);
		return 0;
}