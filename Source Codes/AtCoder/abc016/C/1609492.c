#include<stdio.h>

int main(void){
    int n,m,a,b,w[16][16]={0},i,j,k,r;
    scanf("%d%d",&n,&m);
    for(i = 1;i <= m;i++){
        scanf("%d%d",&a,&b);
        w[a][b]=1;w[b][a]=1;
    }
    for(i=1;i<=n;i++){
        r=0;
        for(j=1;j<=n;j++){
            if(w[i][j]==1 || i==j){continue;}
            for(k=1;k<=n;k++){
                if(w[i][k] && w[k][j]){r++;break;}
            }
        }
        printf("%d\n",r);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^