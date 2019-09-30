#include <stdio.h>
#include <string.h>

int main(void)
{
	int i,n,l,r,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
		scanf("%d%d",&l,&r);
		sum+=r-l+1;
		}
	printf("%d\n",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&l,&r);
   ^