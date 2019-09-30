#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


int min(int a ,int b){
	if(a<b){
		return a;
	}
	return b;
}



int main(){
	int n,i,power;
	int dp[100003]={};
	scanf("%d",&n);
	for (i = 0; i < 6; i++) {
		dp[i]=i;
	}
	for (i = 1; i < 100002; i++) {
		dp[i]=100000;
		power=1;
		while (power<=i){
			dp[i]=min(dp[i],dp[i-power]+1);
			power*=6;
		}
		power=1;
		while (power<=i){
			dp[i]=min(dp[i],dp[i-power]+1);
			power*=9;
		}
	}
	printf("%d",dp[n]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^