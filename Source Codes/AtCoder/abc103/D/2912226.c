#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

typedef struct pair{ll x,y;}P;
int pcmp(const void*a,const void*b){
	if((*(P*)a).y<(*(P*)b).y)return -1;
	return 1;
}

P kukan[100010];

int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	rep(i,0,m){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		kukan[i].x=x;
		kukan[i].y=y;
	}
	qsort(kukan,m,sizeof(P),pcmp);
	
	ll pre=-1;
	ll ans=0;
	rep(i,0,m){
		if(pre<kukan[i].x){
			ans++;
			pre=kukan[i].y-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^