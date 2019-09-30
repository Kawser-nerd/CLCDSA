#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll a[100010];
int main(){
	ll n;
	scanf("%lld",&n);
	rep(i,0,n+1)scanf("%lld",a+i+1);
	ll ans=0,crr=1;
	while(crr!=2&&crr!=-1){
		ll temp=a[crr];
		a[crr]=-1;
		crr=temp;
		ans++;
	}
	printf("%lld",crr==2?ans:-1);
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:15:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n+1)scanf("%lld",a+i+1);
              ^