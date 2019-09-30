#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

typedef struct ppp{ll x,v;}P;

int hikaku(const void*p,const void*q){
	P pp=*(P*)p,qq=*(P*)q;
	if(pp.x<qq.x)return -1;
	return 1;
}

P d[100010];
ll l[100010],r[100010];
ll lM[100010],rM[100010];
int main(){
	ll n,c;
	scanf("%lld%lld",&n,&c);
	rep(i,0,n)scanf("%lld%lld",&(d[i].x),&(d[i].v));
	qsort(d,n,sizeof(P),hikaku);
	
	l[0]=0;
	rep(i,0,n)l[i+1]=l[i]+d[i].v-(i?d[i].x-d[i-1].x:d[i].x);
	lM[0]=0;
	rep(i,0,n)lM[i+1]=max(lM[i],l[i+1]);
	
	r[0]=0;
	rep(i,0,n)r[i+1]=r[i]+d[n-1-i].v-(i?d[n-1-(i-1)].x-d[n-1-i].x:c-d[n-1-i].x);
	rM[0]=0;
	rep(i,0,n)rM[i+1]=max(rM[i],r[i+1]);
	
//	rep(i,0,n)printf("%lld ",l[i]);puts("");
//	rep(i,0,n)printf("%lld ",r[i]);
	
	ll ans=0;
	//?????
	rep(i,1,n+1){
		ans=max(ans,l[i]);//??????
		ans=max(ans,l[i]-d[i-1].x+rM[n-i]);//?????
	}
	//?????
	rep(i,1,n+1){
		ans=max(ans,r[i]);//??????
		ans=max(ans,r[i]-(c-d[(n-1)-(i-1)].x)+lM[n-i]);//?????
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&c);
  ^
./Main.c:24:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld%lld",&(d[i].x),&(d[i].v));
            ^