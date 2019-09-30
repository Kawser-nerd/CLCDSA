#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

typedef struct pair{ll i,c;}P;
int csort(const void*a,const void*b){
	ll p=(*(P*)a).c,q=(*(P*)b).c;
	return p<q?-1:p>q?1:0;
}


P a[200010];
ll flag[100010];
ll cnt[4];
ll n;
int main(){
	scanf("%lld",&n);
	rep(i,0,2*n){
		ll t;
		scanf("%lld",&t);
		a[i].i=i;
		a[i].c=t;
	}
	qsort(a,2*n,sizeof(P),csort);

	ll s=0;
	rep(i,0,n){
		s+=a[i].c;
		flag[a[i].i/2]|=1<<(a[i].i%2);
	}
	rep(i,0,n)cnt[flag[i]]++;

	ll ans=INF;
	
	if(cnt[0]==0&&cnt[1]!=0&&cnt[2]!=0){
		//?????
		rep(i,n,2*n){
			//i???????
			//??????????????????????????????????cnt?1??????
			if(a[n-1].i/2==a[i].i/2&&cnt[flag[a[i].i/2]]!=1){
				ans=min(ans,s+a[i].c-a[n-2].c);
			}else{
				ans=min(ans,s+a[i].c-a[n-1].c);
				//?????????????
				break;
			}
		}
	}else{
		ans=s;
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^