#include <stdio.h>

typedef long long ll;

ll mod=1000000007ll;

ll power(ll a,ll e,ll modP){
	ll ret=1ll;
	for(;e>0ll;e/=2ll){
		if(e%2ll!=0ll){
			ret=(ret*a)%modP;
		}
		a=(a*a)%modP;
	}
	return ret;
}

int main(){

	ll A,B,C;

	scanf("%lld",&A);
	scanf("%lld",&B);
	scanf("%lld",&C);

	A%=mod;
	B%=mod;
	C%=mod;

	ll AB=(A*B)%mod;
	ll BC=(B*C)%mod;
	ll AC=(A*C)%mod;

	ll r=((BC-AC+mod)%mod)*power(AB-BC+AC,mod-2ll,mod);
	ll c=((BC-AB+mod)%mod)*power(AB-BC+AC,mod-2ll,mod);

	r%=mod;
	c%=mod;

	if(r<0){r+=mod;}
	if(c<0){c+=mod;}

	printf("%lld %lld\n",r,c);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&A);
  ^
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&B);
  ^
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&C);
  ^