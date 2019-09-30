#include "stdio.h"
#include "string.h"
#define N 20
#define M 200
int f[1<<N];
int n,m,a[M],b[N][M],c[N],L[N],s[N];
inline int min(int a,int b)
{
	if(a<b)return a;else return b;
}
int main()
{
	int _,__,i,j,k;
	scanf("%d",&_);
	for(__=1;__<=_;__++)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)scanf("%d",a+i),a[i]--;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",c+i,L+i),c[i]--;
			for(j=0;j<L[i];j++)
				scanf("%d",b[i]+j),b[i][j]--;
		}
		memset(f,-1,sizeof f);
		f[(1<<n)-1]=0;
		for(i=(1<<n)-1;i>=0;i--)if(f[i]!=-1)
		{
			memset(s,0,sizeof s);
			for(j=0;j<m;j++)s[a[j]]++;
			for(j=0;j<n;j++)if((i>>j)&1)
			{
				s[c[j]]--;
				for(k=0;k<L[j];k++)s[b[j][k]]++;
			}
			for(j=0;j<n;j++)if((i>>j)&1)
			{
				s[c[j]]++;
				for(k=0;k<L[j];k++)s[b[j][k]]--;
				if(s[c[j]]>=1)
				{
					if(f[i^(1<<j)]==-1)f[i^(1<<j)]=j;
					else f[i^(1<<j)]=min(f[i^(1<<j)],j);
				}
				s[c[j]]--;
				for(k=0;k<L[j];k++)s[b[j][k]]++;
			}
		}
		printf("Case #%d: ",__);
		if(f[0]==-1)puts("IMPOSSIBLE");else
		{
			i=j=0;
			while(i!=(1<<n)-1)
			{
				printf("%d",f[i]+1);
				if(j==n-1)puts("");else printf(" ");
				j++;
				i^=(1<<f[i]);
			}
		}
	}
	return 0;
}