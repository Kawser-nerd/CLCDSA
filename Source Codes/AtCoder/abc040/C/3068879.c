#include <stdio.h>

int a[100005];
int dp[100005];

int min(int a,int b){
	if(a<b){return a;}
	else{return b;}
}
int max(int a,int b){
	if(a>b){return a;}
	else{return b;}
}

int main() {

	int N;

	scanf("%d",&N);

	int i,j;

	for(i=0;i<N;i++){
		scanf(" %d",&a[i]);
		dp[i]=1000000007;
	}

	dp[0]=0;
	for(i=0;i<N-1;i++){
		dp[i+1]=min(dp[i+1],dp[i]+max(a[i+1]-a[i],a[i]-a[i+1]));
		if(i+2<N){
			dp[i+2]=min(dp[i+2],dp[i]+max(a[i+2]-a[i],a[i]-a[i+2]));
		}
	}
	printf("%d\n",dp[N-1]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d",&a[i]);
   ^