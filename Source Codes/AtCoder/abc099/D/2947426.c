#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    int N,C;
    scanf("%d%d",&N,&C);
    int d[C][C];
    for (int i=0; i<C; i++){
        for (int j=0; j<C; j++){
            scanf("%d",&d[i][j]);
        }
    }
    int c[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%d",&c[i][j]);
        }
    }
    int sum1[C],sum2[C],sum3[C];
    for (int i=0; i<C; i++){
        sum1[i]=0;
        sum2[i]=0;
        sum3[i]=0;
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<C; k++){
                if ((i+j)%3==0){
                    sum1[k]+=d[c[i][j]-1][k];
                } else if ((i+j)%3==1){
                    sum2[k]+=d[c[i][j]-1][k];
                } else {
                    sum3[k]+=d[c[i][j]-1][k];
                }
            }
        }
    }
    int ans=INT_MAX,tmp=0;
    for (int i=0; i<C; i++){
        for (int j=0; j<C; j++){
            for (int k=0; k<C; k++){
                if (i!=j && j!=k && k!=i){
                    tmp=sum1[i]+sum2[j]+sum3[k];
                    if (ans>tmp){
                        ans=tmp;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&N,&C);
     ^
./Main.c:14:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&d[i][j]);
             ^
./Main.c:20:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&c[i][j]);
             ^