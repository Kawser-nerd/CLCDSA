#include <stdio.h>

int main(void)
{
	int n,k,min=0,i,x;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		{
		scanf("%d",&x);
		if(x<=k/2){min+=2*x;}
		else{min+=2*(k-x);}
		}
	printf("%d",min);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^