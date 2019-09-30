#include <stdio.h>
#include <stdlib.h>
int W,H;
int N;
int X[30],Y[30];
int sX[32],sY[32];
int dp[32][32][32][32]={0};

int dfs(int x1,int x2, int y1,int y2){
    //printf("%d %d %d %d\n",sX[x1],sX[x2],sY[y1],sY[y2]);
    if(dp[x1][x2][y1][y2]!=0)return dp[x1][x2][y1][y2];
    int i,j;
    int n=0;
    for(i=0;i<N;i++){
        int tmp=sX[x2]-sX[x1]-1+sY[y2]-sY[y1]-1-1;
        int tx=0,ty=0;
        if(sX[x1]<X[i]&&X[i]<sX[x2]&&sY[y1]<Y[i]&&Y[i]<sY[y2]){
            for(j=1;j<=N;j++){
                if(sX[j]==X[i])tx=j;
                if(sY[j]==Y[i])ty=j;
                if(tx&&ty)break;
            }
            tmp+=dfs(x1,tx,ty,y2);
            tmp+=dfs(tx,x2,ty,y2);
            tmp+=dfs(x1,tx,y1,ty);
            tmp+=dfs(tx,x2,y1,ty);
            if(n<tmp)n=tmp;
        }
    }
    return dp[x1][x2][y1][y2]=n;
}

int main(){
    scanf("%d %d",&W,&H);
    scanf("%d",&N);
    int i,j;
    for(i=0;i<N;i++){
        scanf("%d %d",&X[i],&Y[i]);
        sX[i+1]=X[i];
        sY[i+1]=Y[i];
    }
    sX[0]=0;sX[N+1]=W+1;
    sY[0]=0;sY[N+1]=H+1;
    for(i=1;i<N;i++)for(j=i;j<N;j++){
        if(sX[j]>sX[j+1]){
            int tmp=sX[j];
            sX[j]=sX[j+1];
            sX[j+1]=tmp;
        }
        if(sY[j]>sY[j+1]){
            int tmp=sY[j];
            sY[j]=sY[j+1];
            sY[j+1]=tmp;
        }
    }
    //for(i=0;i<N+2;i++)printf("%d %d\n",sX[i],sY[i]);
    int ans=dfs(0,N+1,0,N+1);
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&W,&H);
     ^
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:38:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&X[i],&Y[i]);
         ^