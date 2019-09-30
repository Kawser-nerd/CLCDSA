#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
	int u,v,w;
	edge(int a,int b,int c):u(a),v(b),w(c){}
	bool operator<(const edge &b)const{return w<b.w;}
};
int n,p[110000];
pair<int,int> x[110000],y[110000];
vector<edge> e;
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i].first,&y[i].first);
		x[i].second=y[i].second=i;
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	for(int i=1;i<n;i++)e.push_back(edge(x[i].second,x[i+1].second,x[i+1].first-x[i].first));
	for(int i=1;i<n;i++)e.push_back(edge(y[i].second,y[i+1].second,y[i+1].first-y[i].first));
	for(int i=1;i<=n;i++)p[i]=i;
	sort(e.begin(),e.end());
	long long ans=0;
	for(int j=0;j<e.size();j++)
	{
		int u=find(e[j].u),v=find(e[j].v);
		if(u==v)continue;
		ans+=e[j].w;
		p[u]=v;
	}
	printf("%lld\n",ans);
	return 0;
}