#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

ll n,a,b;
ll p[5010];
ll ip[5010];//p????
ll cnt[5010][5010];//cnt[i][j]=??[i,j)??????p[i]??????????
ll memo[5010][5010];
ll f(int R,int K){
	if(R<=0||K<0)return 0;
	if(memo[R][K])return memo[R][K]-1;
	if(ip[K]>=R)return (memo[R][K]=f(R,K-1)+1)-1;
	
	ll ans;
	if(cnt[ip[K]][R]){
		ll v1=f(ip[K],K-1)+cnt[ip[K]][R]*b;
		ll v2=f(    R,K-1)+a;
		ans=min(v1,v2);
	}else{
		ans=f(R,K-1);
	}
	return (memo[R][K]=ans+1)-1;
}

int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		t--;
		p[i]=t;
		ip[t]=i;
	}
	rep(i,0,n){
		ll c=0;
		rep(j,i+1,n+1){
			cnt[i][j]=c;
			if(p[j]<p[i])c++;
		}
	}
	printf("%lld",f(n,n-1));
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&a,&b);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^