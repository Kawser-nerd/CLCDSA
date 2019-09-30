#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll cnt;
ll ans[300010];

int main(){
	ll k,n;
	scanf("%lld%lld",&k,&n);
	if(k%2==0){
		printf("%lld ",k/2);
		rep(i,1,n)printf("%lld ",k);
		return 0;
	}
	rep(i,0,n)ans[i]=(k+1)/2;
	cnt=n;
	rep(xx,0,n/2){
		ans[cnt-1]--;
		if(ans[cnt-1]){
			rep(j,cnt,n)ans[j]=k;
			cnt=n;
		}else cnt--;
	}
	for(int i=0;ans[i];i++)printf("%lld ",ans[i]);
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&k,&n);
  ^