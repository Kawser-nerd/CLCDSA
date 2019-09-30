#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll k;
ll dp[99][100010];
//dp[s][m]=mod k?m????????s??????(bool)
int main(){
	scanf("%lld",&k);
	
	rep(i,1,9)dp[i][i]=1;
	rep(s,1,50){
		//???0?1??????
		rep(m,0,k)if(dp[s][m]){
			ll mm=m*10%k;
			while(!dp[s][mm]){
				dp[s][mm]=1;
				mm=mm*10%k;
			}
		}
		//???1?9?1????
		rep(m,0,k)if(dp[s][m])rep(d,1,10)dp[s+d][(m*10+d)%k]=1;
		
		if(dp[s][0]){
			printf("%lld\n",s);
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&k);
  ^