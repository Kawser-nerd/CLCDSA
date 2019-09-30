#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define min(p,q)((p)<(q)?(p):(q))

ll a[60];
ll s[60];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);

	ll ans=INF;
	rep(x,0,n+1){
		//????????S=k(n+1)+x?????
		//a[i]?????(a[i]+S)%(n+1)??????
		//a[i]?????????s[i]????
		//a[i]+S-(n+1)*s[i]=(a[i]+x)%(n+1)??
		//s[i]=(a[i]+x)/(n+1)+k
		//?????????
		//S=kn+?(a[i]+x)/(n+1)??
		//k=-x+?(a[i]+x)/(n+1)
		//S>=0??s[i]>=0??(a[i]+S)%(n+1)!=n????????
		
		ll k=-x;
		rep(i,0,n)k+=s[i]=(a[i]+x)/(n+1);
		ll S=k*(n+1)+x;
		int f=1;
		rep(i,0,n)f&=s[i]+k>=0&&(a[i]+S)%(n+1)!=n;
		if(S>=0&&f)ans=min(ans,S);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^