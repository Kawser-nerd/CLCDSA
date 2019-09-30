#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int ni;
	char buf[61];
	int dic[127];
	int cnt;
	for (ni=1;ni<=n;ni++)
	{
		scanf("%s",buf);
		cnt=0;
		int len=strlen(buf);
		int bi;
		for (bi=0;bi<127;bi++)
			dic[bi]=-1;
		for (bi=0;bi<len;bi++)
		{
			if (dic[buf[bi]]==-1)
			{
				dic[buf[bi]]=cnt++;
				if (dic[buf[bi]]==0) dic[buf[bi]]=1;
				else if (dic[buf[bi]]==1) dic[buf[bi]]=0;
			}
		}
		long long result=0;
		for (bi=0;bi<len;bi++)
		{
			result*=cnt;
			result+=dic[buf[bi]];
		}
		printf("Case #%d: %lld\n",ni,result);
	}
	return 0;
}
