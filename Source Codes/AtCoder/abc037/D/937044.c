#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))

#define MOD 1000000007

typedef struct DP {
	lli val;
	bool bl;
} DP;

lli solve(int i,int j,DP **dp,lli **a){
	if(dp[i][j].bl){
		return dp[i][j].val;
	}
	dp[i][j].bl = true;
	dp[i][j].val = 1;
	if(a[i-1][j] > a[i][j]){
		dp[i][j].val += solve(i-1,j,dp,a);
	}
	if(a[i+1][j] > a[i][j]){
		dp[i][j].val += solve(i+1,j,dp,a);
	}
	if(a[i][j-1] > a[i][j]){
		dp[i][j].val += solve(i,j-1,dp,a);
	}
	if(a[i][j+1] > a[i][j]){
		dp[i][j].val += solve(i,j+1,dp,a);
	}
	return dp[i][j].val % MOD;

}


int main(void){
	/* === input paramater === */
	int h;
	int w;
	lli **a;

	/* === paramater === */
	int i;
	int j;
	DP **dp;
	lli ans = 0;
	/* === input === */
	scanf("%d%d",&h,&w);
	a = calloc(sizeof(lli*),h+2);
	for(i=0;i<h+2;i++){
		a[i] = calloc(sizeof(lli),w+2);
		a[i]++;
	}
	a++;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf("%lld",&a[i][j]);
		}
	}

	/* === prepare === */
	dp = calloc(sizeof(DP*),h);
	for(i=0;i<h;i++){
		dp[i] = calloc(sizeof(DP),w);
	}

	/* === output === */
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			ans += solve(i,j,dp,a);
			ans %= MOD;
		}
	}
	printf("%lld\n", ans);



	return 0;
} ./Main.c: In function ‘main’:
./Main.c:53:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:62:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld",&a[i][j]);
    ^