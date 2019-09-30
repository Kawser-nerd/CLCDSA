#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define max3(p,q,r)max(max(p,q),r)
#define min3(p,q,r)min(min(p,q),r)
#define INF ((1LL<<62)-(1LL<<31))


ll ans=INF;

void f(ll h,ll w){
	//h???

	ll hh=h/3;//??1/3???????
	ll rh=h-hh;
	ll c1=hh*w;
	if(w%2==0||rh%2==0){
		ll c2=w*rh/2;
		ans=min(ans,llabs(c1-c2));
	}else{
		//??????
		if(rh>w){
			ll c2=(rh+1)/2*w;
			ll c3=rh*w-c2;
			ans=min(ans,max3(c1,c2,c3)-min3(c1,c2,c3));
		}else{
			ll c2=(w+1)/2*rh;
			ll c3=rh*w-c2;
			ans=min(ans,max3(c1,c2,c3)-min3(c1,c2,c3));
		}
	}
	
	hh=h/3+1;//??1/3?????
	rh=h-hh;
	c1=hh*w;
	if(w%2==0||rh%2==0){
		ll c2=w*rh/2;
		ans=min(ans,llabs(c1-c2));
	}else{
		//??????
		if(rh>w){
			ll c2=(rh+1)/2*w;
			ll c3=rh*w-c2;
			ans=min(ans,max3(c1,c2,c3)-min3(c1,c2,c3));
		}else{
			ll c2=(w+1)/2*rh;
			ll c3=rh*w-c2;
			ans=min(ans,max3(c1,c2,c3)-min3(c1,c2,c3));
		}
	}
	
}

int main(){
	ll h,w;
	scanf("%lld%lld",&h,&w);
	f(h,w);
	f(w,h);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&h,&w);
  ^