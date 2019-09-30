#include <stdio.h>
int main()
{
	int n,m,c,i,j,flag,sum,now;
	int keisu[500];
	sum=0;
	scanf("%d%d%d",&n,&m,&c);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&keisu[i]);
	}
	for(i=1;i<=n;i++)
	{
		flag=0;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&now);
			flag=flag+(now*keisu[j]);
		}
		flag=flag+c;
		if(flag>0)
		{
			sum++;
		}
	}
	printf("%d",sum);
			
			
		
	
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&m,&c);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&keisu[i]);
   ^
./Main.c:17:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&now);
    ^