#include <stdio.h>
#include <stdlib.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	for(int i=0;i<b;i++) a[i]=c;
	return;
}

int dp[101][301];
int main(void)
{
	int n,w,a,b,sum=0,ans=0;
	int i,j,k;
	ll p,m;
	scanf("%d%d",&n,&w);
	FOR(i,0,n){
		scanf("%d%d",&a,&b);
		if(i==0) m=a;
		a-=m;
		for(j=i;j>=0;j--){
			for(k=sum;k>=0;k--){
				dp[j+1][k+a]=MAX(dp[j+1][k+a],dp[j][k]+b);
			}
		}
		sum+=a;
	}
	FOR(i,0,n+1){
		FOR(j,0,sum+1){
			p=m*i+j;
			if(p<=w) ans=MAX(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&w);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^