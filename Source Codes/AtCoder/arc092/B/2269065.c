#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll a[200010],aa[200010],b[200010];
int n;

int bs(int x){
	//x???????a[i]????index
	if(aa[0]>=x)return 0;
	int l=0,r=n;//a[l]<x<=a[r]
	while(r-l>1){
		int m=(l+r)/2;
		if(aa[m]<x)l=m;
		else r=m;
	}
	return r;
}

int main(){
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n)scanf("%lld",b+i);
	
	ll ans=0;
	rep(k,0,29){
		ll mod=1LL<<(k+1);
		ll cnt=0;
		rep(i,0,n)aa[i]=a[i]%mod;
		sortup(aa,n);
		rep(i,0,n){
			ll bb=b[i]%mod;
			if(bb&(mod/2)){
				//[mod-bb,mod-bb+mod/2)?0
				int l=bs(mod*2/2-bb),r=bs(mod*3/2-bb);
				cnt+=n-(r-l);
			}else{
				//[mod/2-bb,mod-bb)?1
				int l=bs(mod*1/2-bb),r=bs(mod*2/2-bb);
				cnt+=r-l;
			}
		}
		if(cnt%2)ans|=1LL<<k;
	}
	
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:26:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^
./Main.c:27:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",b+i);
            ^