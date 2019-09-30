#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)

ll a,b,n;
ll h[100010];

ll bserch(){
	ll l=0,r=0;//l?NG?r?OK
	rep(i,0,n)r+=(h[i]+b-1)/b;
	while(r-l>1){
		ll m=(l+r)/2;
		ll temp=0;
		rep(i,0,n)if(h[i]-b*m>0)temp+=(h[i]-b*m+(a-b)-1)/(a-b);
		if(temp<=m)r=m;
		else l=m;
	}
	return r;
}

int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	rep(i,0,n)scanf("%lld",h+i);
	printf("%lld\n",bserch());
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&a,&b);
  ^
./Main.c:24:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",h+i);
            ^