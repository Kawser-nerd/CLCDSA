#include"stdio.h"
int main()
{
	int a,b,max;
	int add,minus,m;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
	max=add=a+b;
	minus=a-b;
	m=a*b;
	if(minus>max)
		max=minus;
	if(m>max)
		max=m;
	printf("%d\n",max);
	}
}