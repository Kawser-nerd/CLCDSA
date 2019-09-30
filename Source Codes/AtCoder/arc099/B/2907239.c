#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)((n>>m)&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

int cmp(const void*a,const void*b){
	ll aa=*(ll*)a,bb=*(ll*)b;
	ll sa=0,sb=0;
	while(sa+=aa%10,aa/=10);
	while(sb+=bb%10,bb/=10);
	//aa/sa<bb/sb <==> aa*sb<bb*sa
	aa=*(ll*)a;
	bb=*(ll*)b;
	if(aa*sb<bb*sa)return -1;
	if(aa*sb>bb*sa)return 1;
	if(aa<bb)return -1;
	return 1;
}

ll ans[20000000];
ll cnt;
int main(){
	rep(i,1,100000)if(i%10!=9||i==9){
		ll t=i;
		while(t<1000000000000000){
			ans[cnt++]=t;
			t=t*10+9;
		}
	}
	qsort(ans,cnt,sizeof(ll),cmp);
	ll n;
	scanf("%lld",&n);
	ll ptr=0,M=0;
	rep(i,0,n){
		while(ans[ptr]<=M)ptr++;
		printf("%lld\n",M=ans[ptr]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^