#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define START clock_t start=clock()
#define TIME printf("\n%.3f?\n",(double)(clock()-start)/CLOCKS_PER_SEC)

ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)

#define MOD (7*(1<<26)+1)
#define SIZE (1<<18)

//???fft
void fft(ll*f,int n,ll g){
	ll yy[SIZE];
	ll*x=f,*y=yy,*temp;
	for(int t=1;n>>t;t++){
		ll s=1;
		ll gg=pom(g,n>>t,MOD);
		rep(k,0,1<<(t-1)){
			rep(j,0,n>>t){
				y[(j<<t)+k           ]= (x[(j<<(t-1))+k]+s*x[(j<<(t-1))+n/2+k])%MOD;
				y[(j<<t)+k+(1<<(t-1))]=((x[(j<<(t-1))+k]-s*x[(j<<(t-1))+n/2+k])%MOD+MOD)%MOD;
			}
			s=s*gg%MOD;
		}
		temp=x;x=y;y=temp;
	}
	if(x!=f)rep(i,0,n)f[i]=x[i];
}




ll check[SIZE];
ll dp[SIZE];
ll n;

int main(){
//	START;
	scanf("%lld",&n);
	
	ll r=1;
	while(!check[r]){
		check[r]=1;
		r=r*10%n;
	}
	
	if(check[0]){
		puts("1");
		return 0;
	}
	
	//1????????check
	//???45?????fft??????(TLE)
	ll g=pom(3,(MOD-1)/SIZE,MOD);
	ll ig=invp(g,MOD);
	rep(i,0,SIZE)dp[i]=check[i];
	fft(check,SIZE,g);

	for(ll cnt=2;cnt<=18;cnt++){
		//fft
		fft(dp,SIZE,g);
		//???
		rep(i,0,SIZE)dp[i]=dp[i]*check[i]%MOD;
		//ifft
		fft(dp,SIZE,ig);
		//????
		rep(i,0,n)dp[i]=!!((dp[i]+dp[i+n])%MOD),dp[i+n]=0;
		//????
		if(dp[0]){
			printf("%lld\n",cnt);
//			TIME;
			return 0;
		}
	}
	
	ll ans=0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	printf("%lld\n",ans);
	return 0;
//	TIME;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^