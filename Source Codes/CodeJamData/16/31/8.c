#include <stdio.h>

int main()
{
	int cases;scanf("%d",&cases);
	for (int cs=1;cs<=cases;cs++)
	{
		int n;scanf("%d",&n);
		int cnt[26],s[26],d=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",cnt+i);
			d+=cnt[i];
			s[i]=i;
		}
		printf("Case #%d: ",cs);
		while (d)
		{
			for (int i=0;i<n;i++)
			{
				int p=s[i],t=i;
				while (t && cnt[p]>cnt[s[t-1]])
				{
					s[t]=s[t-1];
					t--;
				}
				s[t]=p;
			}
			while (cnt[s[n-1]]==0) n--;
			if (n==2 && cnt[s[1]]==cnt[s[0]])
			{
				d--;
				cnt[s[1]]--;
				printf("%c",s[1]+'A');
			}
			d--;
			cnt[s[0]]--;
			printf("%c%c",s[0]+'A',d?' ':'\n');
			for (int i=0;i<n;i++)
			{
				if (cnt[i]*2>d) printf("imb: %d\n",cs);
			}
		}
	}
}