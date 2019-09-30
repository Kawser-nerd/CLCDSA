#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXN 100006
#define INF 2100000000
using namespace std;
vector<pair<int,long long> > road[MAXN];
int sum[MAXN],a[MAXN],n,ans[MAXN],cnt,u,v;
long long ret,len,minone=INF;
void DFS(int x,int fa)
{
	sum[x]=1;
	for(int i=0;i<(int)road[x].size();i++)
	{
		int nex=road[x][i].first;
		if(nex==fa) continue;
		DFS(nex,x);
		sum[x]+=sum[nex];
		a[x]=max(a[x],sum[nex]);
	}
	a[x]=max(a[x],n-sum[x]);
	if(a[x]==a[ans[cnt]]) ans[++cnt]=x;
	if(cnt==0||a[x]<a[ans[cnt]])
	{
		cnt=1;
		ans[cnt]=x;
	}
}
void DFSS(int x,int fa)
{
	sum[x]=1;
	for(int i=0;i<(int)road[x].size();i++)
	{
		int nex=road[x][i].first;
		if(x==ans[1]&&nex==ans[2]) continue;
		if(x==ans[2]&&nex==ans[1]) continue;
		if(nex==fa) continue;
		DFSS(nex,x);
		sum[x]+=sum[nex];
		ret+=road[x][i].second*sum[nex];
		if(x==ans[1]) minone=min(minone,road[x][i].second);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%lld",&u,&v,&len);
		road[u].push_back({v,len});
		road[v].push_back({u,len});
	}
	DFS(1,0);
	if(cnt==1)
	{
		ans[2]=0;
		DFSS(ans[1],0);
		printf("%lld",ret*2-minone);
	}
	else
	{
		long long v=0;
		for(int i=0;i<(int)road[ans[1]].size();i++)
		{
			int nex=road[ans[1]][i].first;
			if(nex==ans[2])
			{
				v=road[ans[1]][i].second;
				break;
			}
		}
		DFSS(ans[1],0);
		DFSS(ans[2],0);
		printf("%lld",ret*2+v*(n-1));
	}
}