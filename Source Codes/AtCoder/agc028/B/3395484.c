#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)((n>>m)&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)
ll gcd(ll p,ll q){for(ll t;q;)t=p%q,p=q,q=t;return p;}

ll n;
ll a[100010];
ll c[100010];
ll s1[100010];//??????n
ll s2[100010];//??????n
//[l,r)
#define aa(l,r)(c[r]-c[l])

int main(){
	scanf("%lld",&n);
	rep(i,0,n){
		scanf("%lld",a+i);
		c[i+1]=(c[i]+a[i])%MOD;
	}
	//??????n
	if(n>=2)rep(i,1,n)s1[i]=(aa(0,i)+aa(n-i,n))%MOD;
	//??????n
	if(n>=3){
		ll dd=a[0]+a[n-1];
		rep(i,1,n-1){
			s2[i]=(aa(0,n)*i-dd)%MOD;
			dd=(dd+aa(0,i+1)+aa(n-(i+1),n))%MOD;
		}
	}
	
	
	ll fn=1;
	rep(i,1,n+1)fn=fn*i%MOD;
	
	ll ans=fn*c[n]%MOD;//??
	rep(i,1,n)ans=(ans+fn*invp(i+1,MOD)%MOD*s1[i])%MOD;
	rep(i,1,n-1)ans=(ans+fn*invp(i+1,MOD)%MOD*invp(i+2,MOD)%MOD*2*s2[i])%MOD;
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",a+i);
   ^