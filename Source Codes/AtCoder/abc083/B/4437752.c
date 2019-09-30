#include <stdio.h>

int main(void)
{
	int n,a,b,i=1,div,rest,sum=0,ans=0;
	scanf("%d%d%d",&n,&a,&b);
	while(i <= n)
		{
		sum = 0;
		rest = i;
		for(div=10000;div >= 1;div /= 10)
			{
			sum += rest / div;
			rest = rest % div;
			}
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