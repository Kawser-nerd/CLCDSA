#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)


ll p10[20];
ll temp[20];
ll ans;
void f(ll rest,ll keta,ll c){
	
	if(c>(keta-1)/2){
		//???
		ll t=1;
		rep(i,0,c)t*=10-temp[i]-!i;
		ans+=t;
		return;
	}
	int t=(10-rest%10)%10;
	
	//????
	if(llabs(rest-(p10[keta-1-c*2]-1)*t)<p10[keta-1-c*2]){
		temp[c]=t;
		f((rest-(p10[keta-1-c*2]-1)*t)/10,keta,c+1);
	}
	//????
	if(t!=0&&llabs(rest-(p10[keta-1-c*2]-1)*(t-10))<p10[keta-1-c*2]){
		temp[c]=10-t;
		f((rest-(p10[keta-1-c*2]-1)*(t-10))/10,keta,c+1);
	}
}

int main(){
	ll d;
	scanf("%lld",&d);
		
	p10[0]=1;
	rep(i,1,20)p10[i]=p10[i-1]*10;
	
	rep(i,1,19)f(d,i,0);
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&d);
  ^