#include <stdio.h>

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    int A[N][M];
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        scanf("%d",&A[i][j]);
    }
    int kibousya[M];
    int nozoki[M];
    for(int i=0;i<M;i++){kibousya[i]=0;nozoki[i]=0;}
    int ans=114514;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(nozoki[A[j][k]-1]==0){kibousya[A[j][k]-1]++;break;}
            }
        }
        int maxkibou=0;
        for(int j=0;j<M;j++)if(nozoki[j]==0&&kibousya[j]>=kibousya[maxkibou])maxkibou=j;
        if(ans>kibousya[maxkibou])ans=kibousya[maxkibou];
        nozoki[maxkibou]=1;
        for(int i=0;i<M;i++)kibousya[i]=0;
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&A[i][j]);
         ^