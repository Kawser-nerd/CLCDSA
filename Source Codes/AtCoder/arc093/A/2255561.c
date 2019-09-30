#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll ans;
ll a[100010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%lld",a+i);
	ll ans=0;
	rep(i,0,n+1)ans+=llabs(a[i+1]-a[i]);
	rep(i,1,n+1)printf("%lld\n",ans-llabs(a[i]-a[i-1])-llabs(a[i+1]-a[i])+llabs(a[i+1]-a[i-1]));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:11:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,n+1)scanf("%lld",a+i);
              ^