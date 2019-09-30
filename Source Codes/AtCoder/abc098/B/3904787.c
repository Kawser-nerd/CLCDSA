#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll l[26],r[26];
char s[110];
int main(){
	rep(i,0,26){
		l[i]=1000;
		r[i]=-1;
	}

	ll n;
	scanf("%lld%s",&n,s);
	rep(i,0,n){
		int t=s[i]-'a';
		l[t]=min(l[t],i);
		r[t]=max(r[t],i);
	}
	
	ll ans=0;
	rep(i,1,n){
		int cnt=0;
		rep(j,0,26)if(l[j]<i&&i<=r[j])cnt++;
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%s",&n,s);
  ^