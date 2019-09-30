#include<cstdio>
#include<algorithm>
#define MAXN 200006
using namespace std;
int n,q,a[MAXN],sum[MAXN],vis[MAXN],ans,p,x;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[a[i]]++;
	for(int i=1;i<=n;i++)
	{
		for(int j=max(1,i-sum[i]+1);j<=i;j++)
			vis[j]++;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) ans++;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&p,&x);
		int y=a[p];
		sum[y]--;
		if(y-sum[y]>0)
		{
			vis[y-sum[y]]--;
			if(!vis[y-sum[y]]) ans++;
		}
		a[p]=x;
		if(x-sum[x]>0)
		{
			if(!vis[x-sum[x]]) ans--;
			vis[x-sum[x]]++;
		}
		sum[x]++;
		printf("%d\n",ans);
	}
}