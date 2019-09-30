#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll a[100010];
ll k;
int main(){
	ll n;
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	
	ll x=0;
	rep(i,0,n)x+=a[i];
	ll sumN=n*(n+1)/2;
	
	if(x%sumN){
		puts("NO");
		return 0;
	}
	x/=sumN;
	
	a[n]=a[0];
	rep(i,1,n+1){
		ll t=a[i-1]-a[i]+x;
		if(t<0||t%n){
			puts("NO");
			return 0;
		}
		k+=t/n;
	}
	puts(k==x?"YES":"NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:11:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^