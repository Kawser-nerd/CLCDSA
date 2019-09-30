#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,t,ans,smax,j,ct;
	char s[1005];
	scanf("%d",&t);
	for(i = 1; i <= t; i++)
	{
		ans = 0;
		ct = 0;
		scanf("%d %s",&smax,s); //check
		for(j = 0; j <= smax; j++)
		{
			if(j==0)
			{
				ct += s[j]-48;
				if( ct == 0)
				{
					ans++;
				}
			}
			else
			{
				if( (ct+ans) <= j )
				{
					ans += (j-ct-ans);
				}
				ct += s[j]-48;
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}