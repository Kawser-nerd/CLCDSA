#include<stdio.h>

#define mod 1000000007

int ru2(int n){
	int i,r=1;
	for(i=0;i<n;i++)r=r*2;
	return r;
}

int main(){
	int h,w,i,k,j;
	scanf("%d%d%d",&h,&w,&k);
	long long dp[101][9]={0};
	dp[0][0]=1;
	for(i=0;i<h;i++){
		for(j=0;j<ru2(w-1);j++){
			int tmp[8]={0},k=0,f=0;
			while(j>=(1<<k)){
				tmp[k]=j&(1<<k);
				k++;
			}
			/*printf("%d:",j);
			for(k=0;k<w-1;k++){
				printf("%d",tmp[k]);
			}*/
			for(k=1;k<w-1;k++){
				if(tmp[k-1]!=0&&tmp[k]!=0)f=1;
			}
			//printf(":%d\n",f);
			if(f==0){
				for(k=0;k<w;k++){
					if(k!=w-1){
						if(tmp[k]!=0)dp[i+1][k+1]=(dp[i][k]+dp[i+1][k+1])%mod;
					}
					if(k!=w-1){
						if(tmp[k]!=0)dp[i+1][k]=(dp[i][k+1]+dp[i+1][k])%mod;
					}
					if(k==0&&tmp[k]==0)dp[i+1][0]=(dp[i+1][0]+dp[i][0])%mod;
					else if(k==w-1&&tmp[w-2]==0)dp[i+1][w-1]=(dp[i+1][w-1]+dp[i][w-1])%mod;
					else if(1<=k&&k<=w-2&&tmp[k-1]==0&&tmp[k]==0)dp[i+1][k]=(dp[i+1][k]+dp[i][k])%mod;
				}
			}
		}
	}
	/*for(i=0;i<h+1;i++){
		for(j=0;j<w;j++)printf("%d,",dp[i][j]);
		puts("");
	}*/
	printf("%lld\n",dp[h][k-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&h,&w,&k);
  ^