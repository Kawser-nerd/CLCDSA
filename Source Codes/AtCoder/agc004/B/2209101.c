#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll n,t;
ll a[2010],m[2010];
ll ans=INF;

int main(){
	scanf("%lld%lld",&n,&t);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n)m[i]=INF;
	
	rep(k,0,n){
		rep(i,0,n)m[i]=min(m[i],a[(i-k+n)%n]);
		ll temp=0;
		rep(i,0,n)temp+=m[i];
		ans=min(ans,temp+k*t);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&t);
  ^
./Main.c:14:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^