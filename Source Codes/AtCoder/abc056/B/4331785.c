#include<stdio.h>
int main()
{
	int w,a,b;
	scanf("%d %d %d",&w,&a,&b);
	if(b >= a)
	{
		if(b <= a+w)
		{
			printf("0\n");
		}
		if(b > a+w)
		{
			printf("%d",b-(a+w));
		}
	}
	else if(b < a)
	{
		if(a <= b+w)
		{
			printf("0\n");
		}
		if(a>b+w)
		{
			printf("%d\n",a-(b+w));
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&w,&a,&b);
  ^