#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[210][15];
ll a[210];
ll cnt;
int main(){
	ll n;
	scanf("%lld",&n);
	rep(i,0,n){
		char ss[15];
		scanf("%s",ss);
		ll idx=0;
		while(idx<cnt&&strcmp(s[idx],ss))idx++;
		strcpy(s[idx],ss);
		cnt=max(cnt,idx+1);
		a[idx]++;
	}
	ll m;
	scanf("%lld",&m);
	rep(i,0,m){
		char ss[15];
		scanf("%s",ss);
		ll idx=0;
		while(idx<cnt&&strcmp(s[idx],ss))idx++;
		strcpy(s[idx],ss);
		cnt=max(cnt,idx);
		a[idx]--;
	}
	
	ll ans=0;
	rep(i,0,cnt)ans=max(ans,a[i]);
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",ss);
   ^
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&m);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",ss);
   ^