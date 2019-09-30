#include <stdio.h>
#include <stdlib.h>
#define NUM 1000000007 //10^9+7
int main(void){
	int H,W,K;
	scanf("%d%d%d",&H,&W,&K);
	int A[101][8]={0},i,j,k,l;
	A[0][0] = 1;
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			for(k=0;k<1<<(W-1);k++){//2^(W-1)?????
				int ok = 1;
				for(l=0;l<W-2;l++){//W-2????
					if(((k>>l)&1) && ((k>>(l+1))&1))ok=0;//(k>>l) = k/(2^l),&1??1??????
				}
				//?????????????????????
				if(ok){
					if(j>=1 && ((k>>(j-1))&1)){
						A[i+1][j-1] += A[i][j];
						A[i+1][j-1] %= NUM;
					}else if(j<=W-2 && ((k>>j)&1)){
						A[i+1][j+1] += A[i][j];
						A[i+1][j+1] %= NUM;
					}
					else{
						A[i+1][j] += A[i][j];
						A[i+1][j] %= NUM;
					}
				}
			}
		}
	}
	printf("%d",A[H][K-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&H,&W,&K);
  ^