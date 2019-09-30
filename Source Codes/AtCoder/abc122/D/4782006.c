#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define a 0
#define c 1
#define g 2
#define t 3

int main(){
	int N,i,j,k,l,m;
	scanf("%d",&N);

	unsigned long long ans,mod=1000000007,memo[101][4][4][4]={0};
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				memo[3][i][j][k]=1;
			}
		}
	}
	memo[3][a][g][c]=0;
	memo[3][a][c][g]=0;
	memo[3][g][a][c]=0;

	for(i=3;i<N;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				for(l=0;l<4;l++){
					for(m=0;m<4;m++){
						if(k==a && l==g && m==c)continue;
						if(k==a && l==c && m==g)continue;
						if(k==g && l==a && m==c)continue;
						if(j==a && k==g && m==c)continue;
						if(j==a && l==g && m==c)continue;

						memo[i+1][k][l][m]+=memo[i][j][k][l];
						memo[i+1][k][l][m]%=mod;
					}
				}
			}
		}
	}

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ans+=memo[N][i][j][k];
				ans%=mod;
			}
		}
	}

	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^