#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll x[60],y[60];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%lld%lld",x+i,y+i);
	ll ans=INF;
	rep(i1,0,n)rep(i2,0,n)rep(i3,0,n)rep(i4,0,n){
		ll lx=min(x[i1],min(x[i2],min(x[i3],x[i4])));
		ll rx=max(x[i1],max(x[i2],max(x[i3],x[i4])));
		ll ly=min(y[i1],min(y[i2],min(y[i3],y[i4])));
		ll ry=max(y[i1],max(y[i2],max(y[i3],y[i4])));
		int cnt=0;
		rep(i,0,n)if(lx<=x[i]&&x[i]<=rx&&ly<=y[i]&&y[i]<=ry)cnt++;
		if(cnt>=k)ans=min(ans,(rx-lx)*(ry-ly));
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:12:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld%lld",x+i,y+i);
            ^