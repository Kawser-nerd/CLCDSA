#include<cstdio>
#include<algorithm>
#define MAXN 100006
using namespace std;
long long a[MAXN],x,sta[MAXN],s[MAXN],t[MAXN],ans;
int n,m,top;
int find(long long k,int r)
{
	if(r==0) return 0;
	int l=1;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(a[mid]<=k) l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	//freopen("seq.in","r",stdin);
	//freopen("seq.out","w",stdout);
	scanf("%d%d",&n,&m);
	top=1;
	sta[top]=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&x);
		while(x<=sta[top])
			top--;
		sta[++top]=x;
	}
	m=top;
	for(int i=1;i<=m;i++)
		a[i]=sta[i];
	t[m]=1;
	for(int i=m;i>=1;i--)
	{
		long long now=a[i];
		int p=find(now,i-1);
		while(p)
		{
			t[p]+=(now/a[p])*t[i];
			now%=a[p];
			p=find(now,p-1);
		}
		s[1]+=t[i];
		s[now+1]-=t[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans+=s[i];
		printf("%lld\n",ans);
	}
}