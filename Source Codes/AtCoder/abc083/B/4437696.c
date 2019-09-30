#include <stdio.h>

int main(void)
{
	int n,a,b,i=1,rest,sum=0,ans=0;
	scanf("%d%d%d",&n,&a,&b);
	while(i <= n)
		{
		sum = i / 10000;
		rest = i % 10000;
		sum += rest / 1000;
		rest = rest % 1000;
		sum += rest / 100;
		rest = rest % 100;
		sum += rest / 10;
		rest = rest % 10;
		sum += rest;
		if(sum >= a && sum <= b)
			{ans += i;}
		i++;
		}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^