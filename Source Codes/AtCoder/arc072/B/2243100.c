#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll x,y;
int main(){
	scanf("%lld%lld",&x,&y);
	puts(llabs(x-y)<=1?"Brown":"Alice");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&x,&y);
  ^