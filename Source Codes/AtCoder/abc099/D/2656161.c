#include <stdio.h>

int D[35][35];
int c[505][505];

int main() {

	int N,C;

	scanf("%d %d",&N,&C);

	int i,j,k;

	for(i=1;i<=C;i++){
		for(j=1;j<=C;j++){
			scanf(" %d",&D[i][j]);
		}
	}

	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			scanf(" %d",&c[i][j]);
		}
	}

	int mod0[35]={0};
	int mod1[35]={0};
	int mod2[35]={0};

	for(k=1;k<=C;k++){
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if((i+j)%3==0){
					mod0[k]+=D[c[i][j]][k];
				}
				else if((i+j)%3==1){
					mod1[k]+=D[c[i][j]][k];
				}
				else if((i+j)%3==2){
					mod2[k]+=D[c[i][j]][k];
				}
			}
		}
	}

	int ans=1<<30;

	for(i=1;i<=C;i++){
		for(j=1;j<=C;j++){
			for(k=1;k<=C;k++){
				if(i!=j&&i!=k&&j!=k){
					if(ans>mod0[i]+mod1[j]+mod2[k]){
					ans=mod0[i]+mod1[j]+mod2[k];
					}
				}
			}
		}
	}

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&C);
  ^
./Main.c:16:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %d",&D[i][j]);
    ^
./Main.c:22:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %d",&c[i][j]);
    ^