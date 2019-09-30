#include <stdio.h>

int main(void){
	int N,C;
	int i,j,ans;
	scanf("%d %d",&N,&C);
	int D[C][C],color[3][30];
	for(i=0;i<C;i++){
		for(j=0;j<C;j++){
			scanf("%d",&D[i][j]);
		}
	}
	int x;
	for(i=0;i<3;i++){
		for(j=0;j<30;j++){
			color[i][j]=0;
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&x);
			color[(i+j)%3][x-1]++;// %3????????x???????
		}
	}
		
	ans = 1e9;int k,l;
	for(i=0;i<C;i++){
		for(j=0;j<C;j++){
			if(i != j){
				for(k=0;k<C;k++){
					if(i != k && j != k){
						int a = 0;
						for(l=0;l<C;l++){
							a += D[l][i]*color[0][l]; //%3=0????l???i??????
							a += D[l][j]*color[1][l]; //%3=1????l???j??????
							a += D[l][k]*color[2][l]; //%3=2????l???k??????
						}
						if(a < ans) ans = a;
					}
				}
			}
		}
	}
	
	
	printf("%d",ans);
	return 0;} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&C);
  ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&D[i][j]);
    ^
./Main.c:21:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&x);
    ^