#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	long long unsigned i,T,j,ok=1,k,tmp,t;
	char ll[30];
	long long unsigned v[30];
	scanf("%llu\n",&T);
	for (i=0;i<T;i++)
	{
		memset(ll,0,30);
		scanf("%s",ll);
		memset(v,0,30*sizeof(long long));

		ok=1;
		t= strlen(ll);
		while(t && ok)
		{
			//printf("%lld ",ll%10);
			for (k=ll[t-1]-'0'+1;k<10;k++)
				if (v[k]!=0)
				{
					ok = 0;
					break;
				}
			v[ll[t-1]-'0']++;
			t--;
		}

		//printf("%lld %lld\n",ll,k);
		if (!ok)
		{
			ll[t++] = k+'0';
			v[k]--;

			for (k=0;k<10;k++)
				for (j=0;j<v[k];j++)
					ll[t++] = k+'0';

			printf("Case #%llu: %s\n",i+1,ll);
		}
		else
		{
			for (k=1;k<10;k++)
			if (v[k])
			{
				ll[t++]=k+'0';
				ll[t++]='0';
				v[k]--;
				break;
			}

			for (k=0;k<10;k++)
				for (j=0;j<v[k];j++)
					ll[t++] = k+'0';
			printf("Case #%llu: %s\n",i+1,ll);
		}
		
	}
}
