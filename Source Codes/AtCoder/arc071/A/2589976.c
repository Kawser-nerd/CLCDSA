#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll a[200];
ll t[200];
ll n;
char s[200];
int main(){
	rep(i,'a','z'+1)a[i]=INF;
	scanf("%lld\n",&n);
	rep(i,0,n){
		scanf("%s",s);
		ll k=strlen(s);
		rep(i,'a','z'+1)t[i]=0;
		rep(i,0,k)t[s[i]]++;
		rep(i,'a','z'+1)a[i]=min(a[i],t[i]);
	}
	rep(i,'a','z'+1)rep(j,0,a[i])putchar(i);
	puts("");
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld\n",&n);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^