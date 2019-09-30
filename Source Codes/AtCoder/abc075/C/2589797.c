#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

//union-find
#define LIMIT 100
int uniroot[LIMIT+10],unicnt[LIMIT+10];
void ufinit(int n){for(int i=0;i<n;i++){uniroot[i]=i;unicnt[i]=1;}}
int root(int x){return uniroot[x]!=x?uniroot[x]=root(uniroot[x]):x;}
int same(int x,int y){return root(x)==root(y);}
void uni(int x,int y){if((x=root(x))==(y=root(y)))return;uniroot[x]=y;unicnt[y]+=unicnt[x];}

ll n,m;
ll a[60],b[60];
ll ans;
int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,m)scanf("%lld%lld",a+i,b+i);
	rep(i,0,m){
		ufinit(n);
		rep(j,0,m)if(i!=j)uni(a[j]-1,b[j]-1);
		if(unicnt[root(1)]!=n)ans++;
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:23:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,m)scanf("%lld%lld",a+i,b+i);
            ^