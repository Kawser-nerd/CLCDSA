#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[20];
int main(){
	scanf("%s",s);
	ll n=strlen(s);
	if(n==1){
		printf("%s\n",s);
		return 0;
	}
	ll flag=1;
	rep(i,1,n)flag&=(s[i]=='9');
	printf("%lld\n",(n-1)*9+(s[0]-48)-1+flag);
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^