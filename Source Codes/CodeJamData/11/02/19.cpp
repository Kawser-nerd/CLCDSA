#include <stdio.h>
#include <string.h>

int T,n,i,k,j,t;
bool d[30][30];
int m[30][30];
int ans[200];
char s[10000];

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(m,-1,sizeof(m));
		while(n--)
		{
			scanf("%s",&s);
			m[s[0]-'A'][s[1]-'A']=m[s[1]-'A'][s[0]-'A']=s[2]-'A';
		}
		scanf("%d",&n);
		memset(d,0,sizeof(d));
		while(n--)
		{
			scanf("%s",&s);
			d[s[0]-'A'][s[1]-'A']=d[s[1]-'A'][s[0]-'A']=1;
		}
		scanf("%d%s",&n,&s);
		k=0;
		for(i=0;i<n;i++)
		{
			ans[k]=s[i]-'A';
			k++;
			for(j=k-1;j;j--)
				if(m[ans[j]][ans[j-1]]!=-1)
					ans[j-1]=m[ans[j]][ans[j-1]];
				else
					break;
			k=j+1;
			for(j=0;j<k;j++)
				if(d[ans[j]][ans[k-1]])
				{
					k=0;
					break;
				}
		}
		printf("Case #%d: [",++t);
		for(i=0;i<k;i++)
		{
			printf("%c",ans[i]+'A');
			if(i!=k-1)
				printf(", ");
		}
		printf("]\n");
	}
	return 0;
}

