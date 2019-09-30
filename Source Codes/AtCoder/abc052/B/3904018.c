#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[110];
int main(){
	ll n;
	scanf("%lld%s",&n,s);
	ll ans=0,crr=0;
	rep(i,0,n){
		if(s[i]=='I')crr++;
		else crr--;
		ans=max(ans,crr);
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%s",&n,s);
  ^