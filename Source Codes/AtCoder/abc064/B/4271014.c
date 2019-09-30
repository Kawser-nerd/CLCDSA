#include <stdio.h>
#include <string.h>

int main(void)
{
	int n,i;
	scanf("%d",&n);
	int s[n];
	for(i=0;i<=n-1;i++)
		{scanf("%d",&s[i]);}
	
	int min=s[0],max=s[0];
	for(i=0;i<=n-1;i++)
		{
		if(s[i]>max){max=s[i];}
		else if(s[i]<min){min=s[i];}
		}
	int dis=max-min;
	printf("%d",dis);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   {scanf("%d",&s[i]);}
    ^