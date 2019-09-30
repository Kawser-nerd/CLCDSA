#include <stdio.h>

int main(void){
    int N,K;
    scanf("%d %d",&N,&K);
    int po[2*K][2*K];
    for(int i=0;i<2*K;i++)for(int j=0;j<2*K;j++)po[i][j]=0;
    int x,y;
    char c;
    for(int i=0;i<N;i++){
        scanf("%d %d %c",&x,&y,&c);
        if(c=='B')po[x%(2*K)][y%(2*K)]++;
        else po[x%(2*K)][y%(2*K)]--;
    }
    for(int i=0;i<2*K;i++)for(int j=1;j<2*K;j++)po[i][j]+=po[i][j-1];
    for(int i=0;i<2*K;i++)for(int j=1;j<2*K;j++)po[j][i]+=po[j-1][i];
    int ans=0;
    for(int i=0;i<K;i++)for(int j=0;j<K;j++){
        int karians=0;
        karians=2*po[i][j]+2*po[i+K][j+K]-2*po[i][j+K]-2*po[i+K][j]+po[i][2*K-1]+po[2*K-1][j]+po[2*K-1][2*K-1]-po[i+K][2*K-1]-po[2*K-1][j+K];
        karians=karians-(po[2*K-1][2*K-1]-karians);
        if(karians<0)karians*=-1;
        karians=(karians+N)/2;
        if(ans<karians)ans=karians;
     //   printf("%d\n",karians);
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&K);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %c",&x,&y,&c);
         ^