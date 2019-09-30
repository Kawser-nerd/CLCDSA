#include <stdio.h>
#define ll long long int
#define NUM 1000000007 //10^9+7

ll calc(ll a,ll b){
	if(b==0) return 1;
	else if(b%2==0){
		ll x = calc(a,b/2);
		return (x*x)%NUM;
	}else return (a*calc(a,b-1))%NUM;
}

ll comb(ll n,ll m){
	ll tmp=1,ttmp=1;
	for(int i=n;i>=n-m+1;i--)tmp=(tmp*i)%NUM;
	for(int i=1;i<=m;i++)ttmp=(ttmp*i)%NUM;
	return (tmp*calc(ttmp,NUM-2))%NUM;
}
int main(void){
	ll h,w;
	scanf("%lld %lld",&w,&h);
	printf("%lld",comb(w+h-2,w-1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&w,&h);
  ^