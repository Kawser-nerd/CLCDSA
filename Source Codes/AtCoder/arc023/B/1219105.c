#include <stdio.h>

int main()
{
	int r,c,d,in,ans = 0,dd,i = 0,j;
	scanf("%d%d%d",&r,&c,&d);
	dd = d % 2;
	for (; i < r; ++i)
	{
		j = 0;
		for (; j < c; ++j)
		{
			scanf("%d",&in);
			if((i+j)%2 == dd && i + j <= d)
			{
				ans = (ans>in?ans:in);
			}
		}
	}
	printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&r,&c,&d);
  ^
./Main.c:13:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&in);
    ^