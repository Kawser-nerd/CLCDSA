#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define true 1
#define false 0

lli **dp;
int *a;
lli *sum;


lli solve(lli n,lli r){
	if(r==0) return 0;
	if(r==1) return 1;
	if(n==1) return INT_MAX;
	if(dp[n][r]) return dp[n][r];
	return dp[n][r] = min(solve(n-1,r),solve(n-1,r-1)+solve(n-1,r-1)*a[n]/sum[n-1]+1);
}



int main(void){
	int i;
	lli n,k;
	scanf("%lld%lld",&n,&k);
	a = calloc(sizeof(int),n+1);
	sum = calloc(sizeof(lli),n+1);
	dp = calloc(sizeof(lli*),n+1);
	for(i=0;i<=n;i++){
		dp[i] = calloc(sizeof(lli),n+1);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	if(sum[n]==k){
		printf("%d\n", 1);
		return 0;
	}
	for(i=0;i<=n;i++){
		if(solve(n,n-i)<=k){
			printf("%lld\n", n-i);
			return 0;
		}
	}



	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^