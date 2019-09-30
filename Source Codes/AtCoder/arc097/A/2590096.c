#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))


char ss[30010][9];
ll n,k;
char s[5010];
int main(){
	scanf("%s%lld",s,&k);
	n=strlen(s);
	ll cnt=0;
	rep(i,0,n)rep(j,1,6){
		rep(k,0,j)ss[cnt][k]=s[i+k];
		cnt++;
	}
	qsort(ss,cnt,9,strcmp);
	ll ans=0,i=0;
	while(ans<k){
		ll t=i;
		while(!strcmp(ss[i],ss[t]))t++;
		ans++;
		i=t;
	}
	puts(ss[i-1]);
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
  qsort(ss,cnt,9,strcmp);
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%lld",s,&k);
  ^