#include<cstdio>
#include<algorithm>
#define INF 2100000006
#define MAXN 100006
using namespace std;
long long m,T,minone,a[MAXN],d[MAXN];
int n,l[MAXN],last;
int find(int x)
{
	int l=1,r=x;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(T-2*(a[x]-a[mid])>0) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	//freopen("computer.in","r",stdin);
	//freopen("computer.out","w",stdout);
	scanf("%d%lld%lld",&n,&m,&T);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		l[i]=find(i);
	minone=INF;
	for(int i=1;i<=n;i++)
	{
		while(last<l[i]-1)
		{
			last++;
			minone=min(minone,d[last-1]-a[last-1]-2*a[last]);
		}
		long long len=a[i]-a[l[i]];
		d[i]=d[l[i]-1]+a[l[i]]-a[l[i]-1]+len+T;
		d[i]=min(d[i],minone+3*a[i]);
	}
	printf("%lld",d[n]+m-a[n]);
}