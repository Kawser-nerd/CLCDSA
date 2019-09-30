#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n,c,k;
ll a[100010];
ll ans;
int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	
	ll ans=0;
	for(ll i=0;i<n;){
		ans++;
		ll t=i;
		while(t<n&&a[t]==a[i])t++;
		if(a[t]<a[i])while(t<n&&a[t]<=a[t-1])t++;
		else while(t<n&&a[t]>=a[t-1])t++;
		i=t;
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:15:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^