#include<string>
#include<iostream>
#include<map>
using namespace std;
int head[200001],num_edge,n,l,p,fa[200001];
struct Edge
{
	int next,to;
}edge[200001];
int v[200001],ans[200001];
void add(int from,int to)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
int find(int x)
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void get_together(int a,int b)
{
    fa[find(a)]=find(b);
}
void dfs1(int x,int tag,map<int,int>&num)
{
	if(v[x]==tag) return ;
	v[x]=tag;
	num[find(x)]++;
	for(int i=head[x];i;i=edge[i].next)
	  dfs1(edge[i].to,tag,num);
}
void dfs2(int x,int tag,map<int,int>&num)
{
	if(v[x]==tag) return ;
	v[x]=tag;
	ans[x]+=num[find(x)];
	for(int i=head[x];i;i=edge[i].next)
	  dfs2(edge[i].to,tag,num);
}
int main(){
	cin>>n>>p>>l;
	for(int i=1;i<=n;i++)
	  fa[i]=i;
	for(int i=1;i<=p;i++)
	{
		int a,b;
		cin>>a>>b;
		get_together(a,b);
	}
	for(int i=1;i<=l;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)
	  if(!v[i])
	  {
	  	map<int,int> num;
	  	dfs1(i,i,num);
	  	dfs2(i,-i,num);
	  }
	for(int i=1;i<=n;i++)
	  cout<<ans[i]<<' ';
}