#include<stdio.h>
#include<math.h>
int main()
{
	long long i,x,y,sum=0;
	scanf("%lld%lld",&x,&y);
	while(x<=y)
	{
		x=x*2;
		sum++;
	}
	printf("%lld\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&x,&y);
  ^