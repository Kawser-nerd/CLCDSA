#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll n,ans;
ll a[200010];
int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	ll sum=a[0],left=0;
	rep(i,1,n){
		while(sum&a[i]){
			ans+=i-left;
			sum^=a[left];
			left++;
		}
		sum^=a[i];
//		printf("%lld %lld %lld\n",left,i,ans);
	}
	printf("%lld\n",ans+(n-left)*(n-left+1)/2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:14:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^