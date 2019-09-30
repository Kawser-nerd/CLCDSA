#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)



typedef struct t{ll l,r,x;}T;
int sort(const void*a,const void*b){
	T*p=(T*)a,*q=(T*)b;
	if((*p).r<(*q).r)return -1;
	return 1;
}

ll dp[310][310][310];
T c[310];
#define add(p,q)(p=(p+q)%MOD)
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	rep(i,0,m){
		ll l,r,x;
		scanf("%lld%lld%lld",&l,&r,&x);
		c[i].l=l;
		c[i].r=r;
		c[i].x=x;
	}
	qsort(c,m,sizeof(T),sort);
	
	ll cnt=0;
	while(c[cnt].r==1){
		if(c[cnt].x>1){
			puts("0");
			return 0;
		}
		cnt++;
	}
	
	dp[1][0][0]=dp[0][1][0]=dp[0][0][1]=1;
	rep(i,2,n+1){
		//i??????
		rep(j,0,i-1)rep(k,0,i-1){
			add(dp[i  ][j][k],dp[i-1][j][k]);
			add(dp[i-1][i][k],dp[i-1][j][k]);
			add(dp[i-1][j][i],dp[i-1][j][k]);
			add(dp[i][i-1][k],dp[j][i-1][k]);
			add(dp[j][i  ][k],dp[j][i-1][k]);
			add(dp[j][i-1][i],dp[j][i-1][k]);
			add(dp[i][k][i-1],dp[j][k][i-1]);
			add(dp[j][i][i-1],dp[j][k][i-1]);
			add(dp[j][k][i  ],dp[j][k][i-1]);
		}
		while(c[cnt].r==i){
			rep(j,0,i)rep(k,0,i){
				int temp=1;
				if(j>=c[cnt].l)temp++;
				if(k>=c[cnt].l)temp++;
				if(temp!=c[cnt].x){
					dp[i][j][k]=0;
					dp[i][k][j]=0;
					dp[j][i][k]=0;
					dp[k][i][j]=0;
					dp[j][k][i]=0;
					dp[k][j][i]=0;
				}
			}
			cnt++;
		}
	}
	ll ans=0;
	rep(j,0,n)rep(k,0,n){
		add(ans,dp[n][j][k]);
		add(ans,dp[j][n][k]);
		add(ans,dp[j][k][n]);
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&l,&r,&x);
   ^