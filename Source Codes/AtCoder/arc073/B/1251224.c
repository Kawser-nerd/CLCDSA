#include<stdio.h>

long long max(long long x,long long y){if(x>y){return x;}return y;}

int main(void){
	long long res=0,n,l,w[128],v[128],i,j,k,dp[128][512]={0};//dp[choose][diff]
	scanf("%lld%lld",&n,&l);
	for(i = 1;i <= n;i++){scanf("%lld%lld",&w[i],&v[i]);}
	for(i = 1;i <= n;i++){
		for(j = (i-1);j >= 0;j--){
			for(k = j*3;k >= 0;k--){
				dp[j+1][k+(w[i]-w[1])] = max(dp[j+1][k+(w[i]-w[1])],dp[j][k]+v[i]);
			}
		}
	}
	for(i = 0;i <= n;i++){
		for(j = 0;j <= 3*i;j++){
			if(w[1]*i+j <= l){res = max(res,dp[i][j]);}
		}
	}
	printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&l);
  ^
./Main.c:8:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= n;i++){scanf("%lld%lld",&w[i],&v[i]);}
                        ^