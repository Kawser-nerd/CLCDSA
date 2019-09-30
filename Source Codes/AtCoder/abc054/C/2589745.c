#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

//next_permutation
void nexp(ll*a,int cnt){
	int l=cnt-1,r=cnt-1;
	ll t;
	while(--l>=0&&a[l]>a[l+1]);
	if(l>=0){
		while(a[l]>a[r])r--;
		t=a[l];a[l]=a[r];a[r]=t;
	}
	for(l++,r=cnt-1;l<r;l++,r--)t=a[l],a[l]=a[r],a[r]=t;
}

ll fact(ll n){ll x=1;while(n)x*=n--;return x;}

ll n,m;
ll e[9][9];
ll a[9]={1,2,3,4,5,6,7,8};
ll ans;

void f(){
	ll flag=1;
	rep(i,0,n-1)flag&=e[a[i]][a[i+1]];
	ans+=flag;
}

int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,m){
		ll p,q;
		scanf("%lld%lld",&p,&q);
		e[p][q]=e[q][p]=1;
	}
	ll cnt=fact(n-1);
	rep(i,0,cnt){
		f();
		nexp(a+1,n-1);
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&p,&q);
   ^