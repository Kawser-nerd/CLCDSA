#include<stdio.h>
#include<math.h>
int main()
{
	long long  x,y,i;
	int sum=0;
	scanf("%lld%lld",&x,&y);
    while(x<=y)
	{
		sum++;
		x*=2;
	} 
	printf("%d",sum);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&x,&y);
  ^