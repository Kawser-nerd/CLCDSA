#include <stdio.h>
#include <string.h>

int main(void)
  {
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	int count[n+1];
	for(i=0;i<=n-1;i++)
		{count[i]=0;}
	for(i=1;i<=m;i++)
		{
		scanf("%d%d",&a,&b);
		count[a-1]++;
		count[b-1]++;
		}
	for(i=0;i<=n-1;i++)
		{printf("%d\n",count[i]);}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^