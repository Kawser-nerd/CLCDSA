#include<stdio.h>

#define mod 1000000007

int main(){
	int n,i;
	int c[200000];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&c[i]);
	long long dp[200000]={0};
	long long dpdp[200001]={0};
	dp[0]=1;
	dpdp[c[0]]=1;
	for(i=1;i<n;i++){
		dp[i]=dp[i-1];
		if(c[i]!=c[i-1])dp[i]+=dpdp[c[i]];
		dp[i]%=mod;
		if(c[i]!=c[i-1])dpdp[c[i]]=dp[i];
		dpdp[c[i]]%=mod;
	}
	printf("%lld\n",dp[n-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&c[i]);
                  ^