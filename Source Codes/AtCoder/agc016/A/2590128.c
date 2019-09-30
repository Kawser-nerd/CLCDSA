#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[110];
ll ans=INF;
int main(){
	scanf("%s",s);
	ll n=strlen(s);
	rep(c,'a','z'+1){
		ll temp=0;
		ll pre=-1;
		s[n]=c;
		for(ll i=0;i<n+1;i++)if(s[i]==c){
			temp=max(temp,i-pre-1);
			pre=i;
		}
		ans=min(ans,temp);
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^