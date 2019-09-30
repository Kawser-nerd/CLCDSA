#include <stdio.h>

int main(){
    int N,C;
    int D[31][31],c;
    scanf("%d %d",&N,&C);
    int i,j,k,l;
    int mod[3][31]={};
    for(i=1;i<=C;i++)
        for(j=1;j<=C;j++)
            scanf("%d",&D[i][j]);
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            scanf("%d",&c);
            mod[(i+j)%3][c]++;
        }
    }
    int ans = 1e9;
    for(i=1;i<=C;i++){
        for(j=1;j<=C;j++){
            for(k=1;k<=C;k++){
                if(i == j || j == k || k == i){
                    continue;
                }
                int S = 0;
                for(l=1;l<=C;l++){
                    S += mod[0][l]*D[l][i];
                    S += mod[1][l]*D[l][j];
                    S += mod[2][l]*D[l][k];
                }
                if(ans > S){
                    ans = S;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&C);
     ^
./Main.c:11:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&D[i][j]);
             ^
./Main.c:14:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&c);
             ^