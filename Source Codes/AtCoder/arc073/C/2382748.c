#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

typedef struct piar{ll l,r;}I;

int hikaku(const void*p,const void*q){
	I pp=*(I*)p,qq=*(I*)q;
	if(pp.l<qq.l)return -1;
	if(pp.l>qq.l)return 1;
	return 0;
}

I a[200010];
ll rm[200010],rM[200010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y){ll t=x;x=y;y=t;}
		a[i].l=x;
		a[i].r=y;
	}
	
	qsort(a,n,sizeof(I),hikaku);
	
	rm[0]=INF,rM[0]=0;
	rep(i,0,n){
		rm[i+1]=min(rm[i],a[i].r);
		rM[i+1]=max(rM[i],a[i].r);
	}
	ll ans=(a[n-1].l-a[0].l)*(rM[n]-rm[n]);

	rep(i,0,n)ans=min(ans,(max(a[n-1].l,rM[i])-min(a[i].l,rm[i]))*(rM[n]-a[0].l));
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^