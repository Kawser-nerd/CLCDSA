#include <stdio.h>
#include <stdlib.h>
#define ll long long int
ll min(ll x,ll y){return x<y?x:y;}
int main(void){
	ll Q,H,S,D,N,ans=0,q,h,s,d;
	scanf("%lld%lld%lld%lld%lld",&Q,&H,&S,&D,&N);
	H = min(H,2*Q);
	S = min(S,2*H);
	if(2*S<D)ans = N*S;
	else ans = N/2*D+S*(N%2);
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld",&Q,&H,&S,&D,&N);
  ^