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

ll gcd(ll p,ll q){for(ll t;q;)t=p%q,p=q,q=t;return p;}

ll n,ans;
ll a[999];
int main(){
	scanf("%lld",&n);
	rep(i,0,n){
		ll a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a<b||d<b)puts("No");
		else if(c>=b)puts("Yes");
		else{
			//a>=b??c<b??d>=b???
			ll g=gcd(b,d);
			if((b-1)/g*g+(a%g)>c)puts("No");
			else puts("Yes");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
   ^