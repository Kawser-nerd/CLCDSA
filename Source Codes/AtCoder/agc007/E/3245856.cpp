#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 132005
using namespace std;
struct pr{
	long long in,out;
	pr(long long _i=0,long long _o=0){in=_i,out=_o;}
};
vector<pr> dp[MAXN],temp1,temp2;
vector<int> e[MAXN];
int n,fa[MAXN],dis[MAXN],son[MAXN][2],d[MAXN];
long long deep[MAXN],lim;
void insert(vector<pr>&v,const pr&i)
{
	int p=v.size()-1;
	if(!~p) v.push_back(i);
	else if(i.out<v[p].out) v.push_back(i);
}
void vector_merge(vector<pr>&v,vector<pr>&l,vector<pr>&r)
{
	v.clear();
	int x=l.size(),y=r.size(),p=0,q=0;
	if(!y) return;
	while(p!=x)
	{
		while(q!=y&&l[p].out+r[q].in<=lim) q++;
		if(q) q--;
		if(l[p].out+r[q].in<=lim) v.push_back(pr(l[p].in,r[q].out));
		p++; 
	}
}
void merge_sort(vector<pr>&v,vector<pr>&l,vector<pr>&r)
{
	v.clear();
	int x=l.size(),y=r.size(),p=0,q=0;
	while(p!=x||q!=y)
	{
		if(p==x) insert(v,r[q++]);
		else if(q==y) insert(v,l[p++]);
		else if(l[p].in<r[q].in) insert(v,l[p++]);
		else insert(v,r[q++]);
	}
}
void dfs(int x)
{
	if(!d[x])
	{
		dp[x].clear();
		dp[x].push_back(pr(deep[x],deep[x]));
		return;
	}
	int ls=son[x][0],rs=son[x][1];
	dfs(ls);
	dfs(rs);
	lim+=2*deep[x];
	vector_merge(temp1,dp[ls],dp[rs]);
	vector_merge(temp2,dp[rs],dp[ls]);
	merge_sort(dp[x],temp1,temp2);
	lim-=2*deep[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&fa[i],&dis[i]);
		deep[i]=deep[fa[i]]+dis[i];
		son[fa[i]][d[fa[i]]++]=i;
	}
	long long l=0,r=1E13,ans=(l+r)/2;
	while(l<r)
	{
		lim=ans,dfs(1);
		if(dp[1].size()) r=ans;
		else l=ans+1;
		ans=(l+r)/2;
	}
	printf("%lld",ans);
}