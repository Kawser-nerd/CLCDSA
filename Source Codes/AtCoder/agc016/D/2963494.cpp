#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#define fi first
#define se second
#define N 100100
using namespace std;

int n,a[N],b[N],cnt,ans,ta,tb,now,fa[N];
map<int,int>mm,ca,cb;
map<int,int>::iterator ia,ib;

int ff(int u){return u==fa[u]?u:fa[u]=ff(fa[u]);}
inline void in(int u){if(!mm[u]) mm[u]=++cnt;}

int main()
{
	int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),ta^=a[i],fa[i]=i;ca[ta]++;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]!=a[i])
		{
			in(a[i]),in(b[i]);
			ca[a[i]]++;
			cb[b[i]]++;
			ans++;
		}
		tb^=b[i];
	}
	cb[tb]++;
	in(ta),in(tb);
	for(ia=ca.begin(),ib=cb.begin();ia!=ca.end();ia++,ib++)
	{
		if((*ia).fi!=(*ib).fi||(*ia).se!=(*ib).se)
		{
			puts("-1");
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			fa[ff(mm[a[i]])]=ff(mm[b[i]]);
		}
	}
	if(ta!=tb) fa[ff(mm[ta])]=ff(mm[tb]);
	for(i=1;i<=cnt;i++) if(i==ff(i)) ans++;
	cout<<ans-1;
}