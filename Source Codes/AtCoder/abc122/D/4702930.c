#include<stdio.h>

#define mod 1000000007

int main(){
	int n,i,j,k,l,m;
	const int a=0,g=1,c=2,t=3;
	long long ans=0;
	long long dp[101][4][4][4]={0};
	scanf("%d",&n);
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				if(i==a&&j==g&&k==c)continue;
				if(i==a&&j==c&&k==g)continue;
				if(i==g&&j==a&&k==c)continue;					
				dp[3][i][j][k]=1;
			}
		}
	}
	for(i=3;i<n;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				for(l=0;l<4;l++){
					for(m=0;m<4;m++){
						if(k==a&&l==g&&m==c)continue;
						if(k==a&&l==c&&m==g)continue;
						if(k==g&&l==a&&m==c)continue;
						if(j==a&&l==g&&m==c)continue;
						if(j==a&&k==g&&m==c)continue;
						dp[i+1][k][l][m]+=dp[i][j][k][l];
						dp[i+1][k][l][m]%=mod;
					}
				}
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ans+=dp[n][i][j][k];
			}
		}
	}
	printf("%lld\n",ans%mod);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^