#include <stdio.h>

int min(int a,int b){if(a>b)return b;return a;}

int main(void){
    int H,W,T;
    scanf("%d %d %d",&H,&W,&T);
    char map[H][W];
    int sx,sy,gx,gy;
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){scanf(" %c",&map[i][j]);if(map[i][j]=='S'){sx=i;sy=j;}if(map[i][j]=='G'){gx=i;gy=j;}}
    int keisu[H][W][19];
    for(int i=0;i<H;i++)for(int j=0;j<W;j++)for(int k=0;k<19;k++)keisu[i][j][k]=1145141919;
    keisu[sx][sy][0]=0;
    for(int po=0;po<H*W;po++){
        for(int i=0;i<H;i++)for(int j=0;j<W;j++)for(int k=0;k<18;k++)if(keisu[i][j][k]!=-1){
            if(i!=0&&(map[i-1][j]=='.'||map[i-1][j]=='G'))keisu[i-1][j][k]=min(keisu[i-1][j][k],keisu[i][j][k]+1);
            if(i!=H-1&&(map[i+1][j]=='.'||map[i+1][j]=='G'))keisu[i+1][j][k]=min(keisu[i+1][j][k],keisu[i][j][k]+1);
            if(j!=0&&(map[i][j-1]=='.'||map[i][j-1]=='G'))keisu[i][j-1][k]=min(keisu[i][j-1][k],keisu[i][j][k]+1);
            if(j!=W-1&&(map[i][j+1]=='.'||map[i][j+1]=='G'))keisu[i][j+1][k]=min(keisu[i][j+1][k],keisu[i][j][k]+1);
            if(i!=0&&map[i-1][j]=='#')keisu[i-1][j][k+1]=min(keisu[i-1][j][k+1],keisu[i][j][k]);
            if(i!=H-1&&map[i+1][j]=='#')keisu[i+1][j][k+1]=min(keisu[i+1][j][k+1],keisu[i][j][k]);
            if(j!=0&&map[i][j-1]=='#')keisu[i][j-1][k+1]=min(keisu[i][j-1][k+1],keisu[i][j][k]);
            if(j!=W-1&&map[i][j+1]=='#')keisu[i][j+1][k+1]=min(keisu[i][j+1][k+1],keisu[i][j][k]);
        }
    }
    int ans=-1;
    for(int i=1;i<19;i++)if((int)(T-keisu[gx][gy][i])/i>ans)ans=(int)(T-keisu[gx][gy][i])/i;
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&H,&W,&T);
     ^
./Main.c:10:46: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<H;i++)for(int j=0;j<W;j++){scanf(" %c",&map[i][j]);if(map[i][j]=='S'){sx=i;sy=j;}if(map[i][j]=='G'){gx=i;gy=j;}}
                                              ^