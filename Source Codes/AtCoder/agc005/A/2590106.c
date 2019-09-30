#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n;
char s[200010];
ll ans;
int main(){
	scanf("%s",s);
	n=strlen(s);
	ll scnt=0;
	rep(i,0,n){
		if(s[i]=='S')scnt++;
		else{
			if(scnt)scnt--;
			else ans++;
		}
	}
	printf("%lld\n",ans*2);
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^