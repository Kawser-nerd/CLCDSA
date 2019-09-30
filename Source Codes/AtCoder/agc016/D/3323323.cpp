#include<cstdio>
#include<map>
#include<algorithm>
#define MAXN 100006
using namespace std;
map<int,int> ma;
int a[MAXN],b[MAXN],n,now,ans,sum[MAXN],cnt,tot,fa[MAXN];
int root(int x)
{
	if(x!=fa[x]) fa[x]=root(fa[x]);
	return fa[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		now^=a[i];
	ma[now]++;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==now&&a[i]!=now) tot++;
		ma[a[i]]++;
		ma[b[i]]--;
		if(a[i]!=b[i]) ans++;
	}
	int ok=-1;
	for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++)
	{
		if(it->second)
		{
			if(ok!=-1)
			{
				printf("-1");
				return 0;
			}
			ok=it->first;
		}
	}
	if(ans&&tot) ans--;
	for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++)
		it->second=++cnt;
	for(int i=1;i<=cnt;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			fa[root(ma[a[i]])]=root(ma[b[i]]);
		}
	}
	for(int i=1;i<=cnt;i++)
		sum[root(i)]++;
	for(int i=1;i<=cnt;i++)
		if(sum[i]>1) ans++;
	printf("%d",ans);
}