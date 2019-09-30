#include <stdio.h>
#include <stdlib.h>
int W,H;
int N;
int X[32],Y[32];
int dp[32][32][32][32]={0};

int dfs(int l,int r, int b,int t){
    if(dp[l][r][b][t]!=0)return dp[l][r][b][t];
    int i,j;
    int n=0;
    for(i=0;i<N;i++){
        int tmp=X[r]-X[l]-1+Y[t]-Y[b]-1-1;
        if(X[l]<X[i]&&X[i]<X[r]&&Y[b]<Y[i]&&Y[i]<Y[t]){
            tmp+=dfs(l,i,i,t);
            tmp+=dfs(i,r,i,t);
            tmp+=dfs(l,i,b,i);
            tmp+=dfs(i,r,b,i);
            if(n<tmp)n=tmp;
        }
    }
    return dp[l][r][b][t]=n;
}

int main(){
    scanf("%d %d",&W,&H);
    scanf("%d",&N);
    int i,j;
    for(i=0;i<N;i++){
        scanf("%d %d",&X[i],&Y[i]);
    }
    X[N]=0;X[N+1]=W+1;
    Y[N]=0;Y[N+1]=H+1;
    printf("%d\n",dfs(N,N+1,N,N+1));
} ./Main.c: In function ‘main’:
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&W,&H);
     ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:30:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&X[i],&Y[i]);
         ^