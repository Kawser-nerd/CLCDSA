#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}

ll n;
ll a[100010];
int main(){
	scanf("%lld",&n);
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		a[t]++;
	}
	ll flag=1;
	if(n%2){
		flag&=(a[0]==1);
		rep(i,1,n){
			if(i%2)flag&=!a[i];
			else flag&=(a[i]==2);
		}
	}else{
		rep(i,0,n){
			if(i%2==0)flag&=!a[i];
			else flag&=(a[i]==2);
		}
	}
	printf("%lld",flag*pom(2,n/2,1000000007));
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^