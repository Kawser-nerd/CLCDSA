#include <stdio.h>
int main(void){
    int N;
    scanf("%d",&N);
    int kari;
    int ruiseki[N+1][N+1];
    for(int i=0;i<=N;i++){ruiseki[i][0]=0;ruiseki[0][i]=0;}
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        scanf("%d",&kari);
        ruiseki[i+1][j+1]=ruiseki[i][j+1]+ruiseki[i+1][j]-ruiseki[i][j]+kari;
    }
    int kcvlex[N*N+1];//tourist
    for(int i=0;i<=N*N;i++)kcvlex[i]=0;
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)for(int k=0;k<i;k++)for(int l=0;l<j;l++){
        if((ruiseki[i][j]-ruiseki[i][l]-ruiseki[k][j]+ruiseki[k][l])>kcvlex[(i-k)*(j-l)])kcvlex[(i-k)*(j-l)]=ruiseki[i][j]-ruiseki[i][l]-ruiseki[k][j]+ruiseki[k][l];
    }
    int Q;
    scanf("%d",&Q);
    for(int t=0;t<Q;t++){
    scanf("%d",&kari);
    int ans=0;
    for(int i=1;i<=kari;i++)if(kcvlex[i]>ans)ans=kcvlex[i];
    printf("%d\n",ans);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&kari);
         ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&Q);
     ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&kari);
     ^