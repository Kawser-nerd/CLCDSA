#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll x[100010];
ll dp[22][100010];
//dp[i][j]=x[j]??2^i????????????index

void f(int a,int b){
	if(a>b){int t=a;a=b;b=t;}
	//a??b????
	ll l=0,r=1<<20,d=19;//l?NG,r?OK
	while(r-l>1){
		if(dp[d][a]>=b)r=l+(1<<d);
		else{
			l=l+(1<<d);
			a=dp[d][a];
		}
		d--;
	}
	printf("%lld\n",r);
}

int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",x+i);
	ll L;
	scanf("%lld",&L);
	
	rep(i,0,n){
		//????
		ll X=x[i]+L;
		ll l=i,r=n;//l?OK,r?NG
		while(r-l>1){
			ll m=(l+r)/2;
			if(x[m]<=X)l=m;
			else r=m;
		}
		dp[0][i]=l;
	}
	
	rep(i,0,20)rep(j,0,n)dp[i+1][j]=dp[i][dp[i][j]];
	
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		f(a-1,b-1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:28:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",x+i);
            ^
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&L);
  ^
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:50:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^