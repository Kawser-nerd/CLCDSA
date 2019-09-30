#include<stdio.h>
#include<string.h>
int main()
{
	char x[200005];
	scanf("%s",x);
	int ans=0;
	int n=strlen(x);
	int i,a;
	a=0;
	for(i=0;i<n;i++)
	{
		if(x[i]=='S')
			a++;
		else if(a>0)
			a--;
		else
			ans++;
	}
	ans+=a;
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",x);
  ^