#include <stdio.h>
#include <string.h>

int main(void)
{
	int n,i;
	scanf("%d",&n);
	int s[n];
	for(i=0;i<=n-1;i++)
		{scanf("%d",&s[i]);}
	int next=1,count=0;
	while(next!=2)
		{
		next=s[next-1];
		count++;
		if(count>n){count=-1;break;}
		}
	printf("%d",count);
	


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   {scanf("%d",&s[i]);}
    ^