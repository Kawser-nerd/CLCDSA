#include<stdio.h>

int main()
{
	int i,n,s[110],c=1,ans=0;
	scanf("%d",&n);
	s[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&(s[i]));
		if(s[i]==s[i-1])c++;
		else c=1;
		if(c%2==0)ans++;
	}
	printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(s[i]));
   ^