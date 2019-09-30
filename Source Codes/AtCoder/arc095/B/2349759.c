#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll a[200010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);
	sortup(a,n);
	ll l1=-1,r1=n-1;//l?OK,r?NG,a[n-1]/2????????
	while(r1-l1>1){
		ll m=(l1+r1)/2;
		if(a[m]<=(a[n-1]+1)/2)l1=m;
		else r1=m;
	}
	ll l2=-1,r2=n;//l?NG,r?OK,(a[n-1]+1)/2????????
	while(r2-l2>1){
		ll m=(l2+r2)/2;
		if(a[m]>=(a[n-1]+1)/2)r2=m;
		else l2=m;
	}
	if(r2==n)printf("%lld %lld\n",a[n-1],a[l1]);
	else if(l1==-1)printf("%lld %lld\n",a[n-1],a[r2]);
	else printf("%lld %lld\n",a[n-1],a[l1]<a[n-1]-a[r2]?a[r2]:a[l1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^