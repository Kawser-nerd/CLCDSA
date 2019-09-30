#include <stdio.h>
#define mod 1000000007 //10^9+7
int main(void){
	int N,A=0,G=1,C=2,T=3;
	long long ans=0,memo[101][4][4][4]={0};
	scanf("%d",&N);
	int i,j,k,l,m;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				if(i==A && j==G && k==C) continue;
				if(i==A && j==C && k==G) continue;
				if(i==G && j==A && k==C) continue;
				memo[3][i][j][k] = 1;
			}
		}
	}
	
	//??????i?i-2???j?i-1???k?i???l??????????i+1???m
	for(i=3;i<N;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				for(l=0;l<4;l++){
					for(m=0;m<4;m++){
						if(k==A && l==G && m==C)continue;
						if(k==A && l==C && m==G)continue;
						if(k==G && l==A && m==C)continue;
						if(j==A && l==G && m==C)continue;
						if(j==A && k==G && m==C)continue;
						memo[i+1][k][l][m] += memo[i][j][k][l];
						memo[i+1][k][l][m] %= mod;
					}
				}
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ans += memo[N][i][j][k];
			}
		}
	}
	
	printf("%lld",ans%mod);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^