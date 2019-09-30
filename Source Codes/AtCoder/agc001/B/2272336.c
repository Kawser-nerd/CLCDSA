#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll ans;
void gcd(ll p,ll q){
	if(p%q){
		ll d=p/q;
		ans+=2*q*d;
		gcd(q,p%q);
	}else{
		ll d=p/q;
		ans+=q*(2*d-1);
	}
}

int main(){
	ll n,x;
	scanf("%lld%lld",&n,&x);
	gcd(x,n-x);
	printf("%lld\n",ans+n);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&x);
  ^