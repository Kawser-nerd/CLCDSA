#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll a,b;
ll ans;
int main(){
	scanf("%lld%lld",&a,&b);
	if(a>b){
		ll t=a;
		a=b;
		b=t;
	}
	if(a==1){
		if(b==1)puts("1");
		else printf("%lld\n",b-2);
	}else{
		printf("%lld\n",(a-2)*(b-2));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&a,&b);
  ^