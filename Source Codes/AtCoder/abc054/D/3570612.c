#include<stdio.h>
#define INF 999999

int dp[41][160801];

int min(int x,int y){
	if(x<y)return x;
	return y;
}

int max(int x,int y){
	if(x>y)return x;
	return y;
}

int main(){
	int N,A,B,i,m=INF;
	scanf("%d%d%d",&N,&A,&B);
	int a[N],b[N],c[N],s[N];
	for(i=0;i<N;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		s[i]=a[i]*401+b[i];
	}
	
	for(i=0;i<41;i++)for(int j=0;j<160801;j++)dp[i][j]=INF;
	dp[0][0]=0;
	for(i=0;i<N;i++){
		for(int j=0;j<160801;j++){
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			if(j>=s[i])dp[i+1][j]=min(dp[i+1][j],dp[i][j-s[i]]+c[i]);
		}
	}
	for(i=1;i<=400/max(A,B);i++){
		if(dp[N][A*i*401+B*i]<m){
			m=dp[N][A*i*401+B*i];
		}
	}
	if(m<INF)printf("%d\n",m);
	else printf("-1\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&A,&B);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a[i],&b[i],&c[i]);
   ^