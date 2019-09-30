#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define sum(n)((n)*((n)+1)/2)


ll a[100010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);
	
	ll l=2,r=2;
	for(int i=n-1;i>=0;i--){
		//l?[l,r]??????a[i]???
		//r?[l,r]??????a[i]???+a[i]-1
		//???????
		ll tl=(l-1+a[i])/a[i]*a[i];
		ll tr=r/a[i]*a[i]+a[i]-1;
		if(tl>r){
			puts("-1");
			return 0;
		}
		l=tl;
		r=tr;
	}
	
	printf("%lld %lld\n",l,r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^