#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define N 200100

struct node {
	ll num;
	int id;
	bool operator < (const node& x) const {
		return x.num<num;
	}
}g[N];
ll c,ans,now;
ll f[N],x[N];
int n,v[N];

/*ll read()
{
	int c=getchar(); ll x=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	return x;
}*/

int main()
{
	scanf("%d%lld",&n,&c);
	for (int i=1;i<=n;i++) scanf("%lld%d",&x[i],&v[i]); x[n+1]=c;
	for (int i=n;i;i--) g[i].num=g[i+1].num+v[i]-(x[i+1]-x[i]),g[i].id=i;
	//g[n+1].num=0; g[n+1].id=n+1;
	sort(g+1,g+n+1);
	int cur=1;
	ans=max(ans,g[1].num);
	for (int i=1;i<=n;i++)
	{
		while (g[cur].id<=i && cur<=n) cur++;
		now+=v[i]-2*(x[i]-x[i-1]);
		ans=max(ans,now+max(0ll,g[cur].num));
	}
	
	for (int i=1;i<=n;i++) g[i].num=g[i-1].num+v[i]-(x[i]-x[i-1]),g[i].id=i;
	sort(g+1,g+n+1);
	cur=1; now=0;
	ans=max(ans,g[1].num);
	for (int i=n;i;i--)
	{
		while (g[cur].id>=i && cur<=n) cur++;
		now+=v[i]-2*(x[i+1]-x[i]);
		ans=max(ans,now+max(0ll,g[cur].num));
	}
	
	printf("%lld\n",ans);
	return 0;
}