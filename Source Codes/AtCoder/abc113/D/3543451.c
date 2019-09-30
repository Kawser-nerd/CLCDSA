#include <stdio.h>
#define MOD 1000000007

long memo[100] = {1,1};
long kkn(long k){
	if(memo[k]!=0){
		return memo[k];
	}else{
		memo[k] = (kkn(k-2)+kkn(k-1)) % MOD;
		return (kkn(k-2)+kkn(k-1)) % MOD;
	}
}

long dp[101][9] ={};
long amida(long h,long w,long k){
	long ans = 0;
	if(h>=2){
		ans += ((kkn(k-1) * kkn(w-k)) % MOD)
		* ((dp[h-1][k]!=0)?dp[h-1][k]:amida(h-1,w,k)) % MOD;
		if(k > 1){
			ans += ((kkn(k-2) * kkn(w-k)) % MOD)
			* ((dp[h-1][k-1]!=0)?dp[h-1][k-1]:amida(h-1,w,k-1)) % MOD;
		}
		if(w > k){
			ans += ((kkn(k-1) * kkn(w-k-1)) % MOD)
			* ((dp[h-1][k+1]!=0)?dp[h-1][k+1]:amida(h-1,w,k+1)) % MOD;
		}
		dp[h][k] = ans % MOD;
		return ans % MOD;
	}else{
		if(k==2) ans=kkn(w-2);
		else if(k==1) ans=kkn(w-1);
		else ans=0;
		dp[h][k] = ans % MOD;
		return ans % MOD;
	}
}

int main(void){
	long h,w,k;
	scanf("%ld %ld %ld",&h,&w,&k);
	printf("%ld\n",amida(h,w,k));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld %ld",&h,&w,&k);
  ^