#include <stdio.h>
#include <stdlib.h>
#define ll long long int

ll p[51],a[51];

ll f(ll n,ll x){
	if(n==0)return 1;
	if(x==1)return 0;
	if(x<=1+a[n-1])return f(n-1,x-1);
	if(x==2+a[n-1])return p[n-1]+1;
	if(x<2+2*a[n-1])return p[n-1]+1+f(n-1,x-2-a[n-1]);
	return 2*p[n-1]+1;
}

int main(void){
	ll x,n;
	scanf("%lld%lld",&n,&x);
	p[0] = 1;
	a[0] = 1;
	for(int i=1;i<=n;i++){
		p[i] = 2*p[i-1]+1;
		a[i] = 2*a[i-1]+3;
	}
	printf("%lld",f(n,x));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&x);
  ^