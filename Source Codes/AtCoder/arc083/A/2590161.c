#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll dp[3000];
ll ansmizu,anssatou;
double noudo;
int main(){
	ll a,b,c,d,e,f;
	scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
	rep(i,0,3001)rep(j,0,3001)if(i*c+j*d<=3000)dp[i*c+j*d]=1;
	
	rep(i,0,31)rep(j,0,31)if(i*a+j*b<=f/100){
		ll mizu=(i*a+j*b)*100;
		ll saidai=min(mizu/100*e,f-mizu);
		while(!dp[saidai])saidai--;
		if(1.0*saidai/(mizu+saidai)>=noudo){
			ansmizu=mizu;
			anssatou=saidai;
			noudo=1.0*saidai/(mizu+saidai);
		}
	}
	printf("%lld %lld\n",ansmizu+anssatou,anssatou);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
  ^