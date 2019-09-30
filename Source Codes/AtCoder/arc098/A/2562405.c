#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll n,ans=INF;
char s[300010];
ll ss[300010];
int main(){
	scanf("%lld\n%s",&n,s+1);
	rep(i,1,n+1)ss[i]=ss[i-1]+(s[i]=='E');
	rep(i,1,n+1)ans=min(ans,(i-1-ss[i-1])+(ss[n]-ss[i]));
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld\n%s",&n,s+1);
  ^