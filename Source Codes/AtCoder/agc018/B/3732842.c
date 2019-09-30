#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define min(p,q)((p)<(q)?(p):(q))

ll a[310][310];
ll d[310];//deleted flag
ll ans=INF;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n)rep(j,0,m)scanf("%lld",&a[i][j]);
	rep(xxx,0,m){
		ll cnt[310]={};
		rep(i,0,n){
			rep(j,0,m)if(!d[a[i][j]]){
				cnt[a[i][j]]++;
				break;
			}
		}
		ll M=0,Mi;
		rep(i,1,m+1)if(M<cnt[i]){
			M=cnt[i];
			Mi=i;
		}
		ans=min(ans,M);
		d[Mi]=1;
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:13:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)rep(j,0,m)scanf("%lld",&a[i][j]);
                      ^