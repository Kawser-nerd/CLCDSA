#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1000005;
struct Edge{int u,v;int w;
inline bool operator <(const Edge &b)const {return w<b.w;}
}e[N];
ll f[N],sum[N];
int fa[N];
int a[N],b[N];
int find(int x){return fa[x]=(fa[x]==x?x:find(fa[x]));}
int main()
{
	//freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,tmp=0;
	cin >>n>>m;
	for(int i=1;i<=n;i++)cin >>a[i]>>b[i],fa[i]=i,sum[i]=b[i],f[i]=max(a[i],b[i]);
	for(int i=1;i<=m;i++)cin >>e[i].u>>e[i].v,e[i].w=max(max(a[e[i].u]-b[e[i].u],0),max(a[e[i].v]-b[e[i].v],0));
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++)if((e[i].u=find(e[i].u))!=(e[i].v=find(e[i].v)))
	{
		f[e[i].u]=min(max(f[e[i].u],(ll)e[i].w)+sum[e[i].v],max(f[e[i].v],(ll)e[i].w)+sum[e[i].u]);
		fa[e[i].v]=e[i].u;
		sum[e[i].u]+=sum[e[i].v];
	}
	cout <<f[find(1)]<<endl;
	//cout <<tmp<<n;
	return 0;
}