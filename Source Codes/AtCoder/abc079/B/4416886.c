#include <stdio.h>
#define int long long

signed main(void)
{
	signed n,i;
	scanf("%d",&n);
	int a=2,b=1,temp;
	for(i=1;i <= n-1;i++)
		{
		temp = a+b;
		a = b;
		b = temp;
		}
	printf("%lld\n",b);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^