#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define maxn 1000010
#define LL long long

using namespace std;

int tt;
int a[maxn];
LL sum[maxn];
int n,p,q,r,s;


int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d%d%d%d",&n,&p,&q,&r,&s);
		for (int i=1;i<=n;++i)
			a[i]=((LL)(i-1)*(LL)p+(LL)q)%r+s;
		sum[0]=0;
		for (int i=1;i<=n;++i)
			sum[i]=sum[i-1]+a[i];

		int j=0;
		while (j<n && sum[j+1]<=sum[n]-sum[j+1]) j++;
		LL ans=sum[n];
		for (int i=1;i<n-1;++i) {
			j=max(j,i+1);
			while (j<n-1 && sum[j+1]-sum[i]<=sum[n]-sum[j+1]) j++;
			LL now=max(sum[i],min(max(sum[n]-sum[j],sum[j]-sum[i]),max(sum[n]-sum[j+1],sum[j+1]-sum[i])));
			ans=min(ans,now);
		}
		if (n==2) ans=max(a[1],a[2]);
		ans=sum[n]-ans;
		printf("Case #%d: ",ii);
		printf("%.12f\n",(double)ans/(double)sum[n]);
	}
}
