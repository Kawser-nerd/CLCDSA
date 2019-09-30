#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long int

ll xor(ll n){
	if(n==-1)return 0;
	ll x;
	if(((n+1)/2)%2==0) x = 0;
	else x = 1;
	if(n%2==0) x ^= n;
	return x;
}

int main(void){
	ll a,b,ans;
	scanf("%lld %lld",&a,&b);
	ll A = xor(a-1);
	ll B = xor(b);
	ans = A^B;
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&a,&b);
  ^