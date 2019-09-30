#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
struct point
{
	int x,y,id;
	point(int a=0,int b=0,int c=0):x(a),y(b),id(c){}
	bool operator<(const point &b)const{return x<b.x||(x==b.x&&y<b.y);}
	bool operator<=(const point &b)const{return x<b.x||(x==b.x&&y<=b.y);}
}p[100001];
inline int dist(point a,point b){return max(abs(a.x-b.x),abs(a.y-b.y));}
int n,s,e,d,vis[100001],ans=0,cnt[100001];
vector<int> w[100001];
void add(int x,int y)
{
	w[p[x].id].push_back(p[y].id);
	w[p[y].id].push_back(p[x].id);
}
void add_edge(int off)
{
	sort(p+1,p+n+1);
	for(int i=1,j=1,l=1,r=1;i<=n;i++)
	{
		point lower=point(p[i].x+d,p[i].y-d+off),upper=point(p[i].x+d,p[i].y+d-off);
		while(l<=n&&p[l]<lower)l++;
		while(r<=n&&p[r]<=upper)r++;
		cnt[p[i].id]+=r-l;
		if(l==r)continue;
		j=max(j,l);
		add(i,l);
		for(;j+1<r;j++)add(j,j+1);
	}
}
void dfs(int u)
{
	vis[u]=1;
	ans+=cnt[u];
	for(int i:w[u])
		if(!vis[i])dfs(i);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s>>e;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		p[i]=point(a-b,a+b,i);
	}
	d=dist(p[s],p[e]);
	add_edge(0);
	for(int i=1;i<=n;i++)swap(p[i].x,p[i].y);
	add_edge(1);
	dfs(s);
	cout<<ans<<endl;
	return 0;
}