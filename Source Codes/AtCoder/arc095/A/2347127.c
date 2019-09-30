#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll a[200010];
ll b[200010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n)b[i]=a[i];
	sortup(b,n);
	ll l=b[n/2-1],r=b[n/2];
	rep(i,0,n)printf("%lld\n",a[i]<=l?r:l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:14:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^