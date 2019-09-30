#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n;
char s[300010];
ll a[300010];
ll ans=INF;
int main(){
	scanf("%lld\n%s",&n,s);
	rep(i,0,n)a[i+1]=a[i]+(s[i]=='E');
	rep(i,0,n)ans=min(ans,(i-a[i])+(a[n]-a[i+1]));
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld\n%s",&n,s);
  ^