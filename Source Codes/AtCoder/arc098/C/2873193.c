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

ll n,k,q,ans=INF;
ll a[2010];
ll temp1[2010];
ll temp2[2010];

int main(){
	scanf("%lld%lld%lld",&n,&k,&q);
	rep(i,0,n)scanf("%lld",a+i);
	a[n]=-1;
	
	while(1){
		ll cnt1=0,cnt2=0;
		rep(i,0,n+1){
			if(a[i]<0){
				if(cnt1>=k){
					sortup(temp1,cnt1);
					rep(j,0,cnt1-(k-1))temp2[cnt2++]=temp1[j];
				}
				cnt1=0;
			}else{
				temp1[cnt1++]=a[i];
			}
		}
		if(cnt2<q)break;
		sortup(temp2,cnt2);
//		rep(i,0,cnt2)printf("%d",temp2[i]);puts("");
		ans=min(ans,temp2[q-1]-temp2[0]);
		rep(i,0,n)if(a[i]==temp2[0])a[i]=-1;
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&k,&q);
  ^
./Main.c:23:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^