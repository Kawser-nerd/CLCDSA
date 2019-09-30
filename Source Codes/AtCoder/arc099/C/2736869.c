#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

ll ee[800][800];
ll a[800];
ll cnt[800],dpcnt;
ll dp[800];
ll cnta,cntb;
ll n,m;
ll base;

void f(ll i,ll c){
	a[i]=c;
	if(c==1)cnta++;
	else cntb++;
	
	rep(j,0,n)if(!ee[i][j]){
		if(a[j]&&a[j]==c){
			puts("-1");
			exit(0);
		}
		if(!a[j])f(j,-c);
	}
}

int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,m){
		ll p,q;
		scanf("%lld%lld",&p,&q);
		ee[p-1][q-1]=ee[q-1][p-1]=1;
	}
	rep(i,0,n)ee[i][i]=1;
	
	rep(i,0,n)if(!a[i]){
		cnta=0;
		cntb=0;
		f(i,1);
		base+=min(cnta,cntb);
		cnt[dpcnt++]=llabs(cnta-cntb);
	}
	
	dp[base]=1;
	rep(i,0,dpcnt)for(ll j=800;j>=cnt[i];j--)dp[j]|=dp[j-cnt[i]];
	dp[0]=1;
	
	
	ll temp,temp2,ans,ans2;
	temp=n/2;
	while(!dp[temp])temp++;
	temp2=n-temp;
	ans=temp*(temp-1)/2+temp2*(temp2-1)/2;

	temp=n/2;
	while(!dp[temp])temp--;
	temp2=n-temp;
	ans2=temp*(temp-1)/2+temp2*(temp2-1)/2;

	printf("%lld\n",min(ans,ans2));
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&p,&q);
   ^