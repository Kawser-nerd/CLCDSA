#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)((n>>m)&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}

#define MOD 1000000007

ll n,h[110];

ll f(ll l,ll r,ll foot,ll*a,ll*b){
	ll m=h[l];
	rep(i,l,r)m=min(m,h[i]);
	ll mcnt=0;
	rep(i,l,r)if(h[i]==m)mcnt++;
	
	ll aa[110],bb[110],cnt=0;
	ll left=l;
	while(left<r){
		while(left<r&&h[left]==m)left++;
		if(left==r)break;
		ll right=left;
		while(right<r&&h[right]!=m)right++;
		f(left,right,m,aa+cnt,bb+cnt);
		cnt++;
		left=right;
	}

	if(cnt){
		*a=1;
		rep(i,0,cnt)*a=*a*(aa[i]+2*bb[i])%MOD;
		*a=*a*pom(2,mcnt,MOD)%MOD;
		*b=1;
		rep(i,0,cnt)*b=*b*bb[i]%MOD;
		*a=(*a-2**b+MOD+MOD)%MOD;
		*b=*b*pom(2,m-foot,MOD)%MOD;
	}else{
		*a=(pom(2,r-l,MOD)-2+MOD)%MOD;
		*b=pom(2,m-foot,MOD);
	}
}

int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",h+i);
	ll a,b;
	f(0,n,0,&a,&b);
	printf("%lld\n",(a+b)%MOD);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:54:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:55:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",h+i);
            ^