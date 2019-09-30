#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n;
ll a[100010];
ll ans1,ans2;
int main(){
	scanf("%lld\n",&n);
	rep(i,0,n)scanf("%lld\n",a+i);
	//????
	ll s=0;
	rep(i,0,n){
		s+=a[i];
		if(i%2){
			//s??
			ans1+=max(1-s,0);
			s=max(1,s);
		}else{
			//s??
			ans1+=max(s+1,0);
			s=min(-1,s);
		}
	}

	//????
	s=0;
	rep(i,0,n){
		s+=a[i];
		if(i%2==0){
			//s??
			ans2+=max(1-s,0);
			s=max(1,s);
		}else{
			//s??
			ans2+=max(s+1,0);
			s=min(-1,s);
		}
	}
	printf("%lld\n",min(ans1,ans2));
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld\n",&n);
  ^
./Main.c:15:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld\n",a+i);
            ^