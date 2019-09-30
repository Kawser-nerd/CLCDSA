#include <stdio.h>

int max(int a,int b){
    if(a>b)return a;
    return b;
}

int main(void){
    int W,N,K;
    scanf("%d %d %d",&W,&N,&K);
    int po[W+1][N+1];
    for(int i=0;i<=W;i++)for(int j=0;j<=N;j++)po[i][j]=-1;
    po[0][0]=0;
    int kari1,kari2;
    for(int buri=0;buri<N;buri++){
        scanf("%d %d",&kari1,&kari2);
        for(int i=N;i>=0;i--)for(int j=W;j>=0;j--){
            if(j+kari1<=W&&po[j][i]!=-1)po[j+kari1][i+1]=max(po[j+kari1][i+1],po[j][i]+kari2);
        }
    }
    int ans=0;
    for(int i=0;i<=W;i++)for(int j=0;j<=K;j++)ans=max(ans,po[i][j]);
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&W,&N,&K);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&kari1,&kari2);
         ^