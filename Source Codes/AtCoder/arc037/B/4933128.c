#include <stdio.h>
#define rep(i,a,n) for(i=(a);i<(n);i++)
int N,M,used[100],graph[100][100];

int dfs(int u,int v){
    if(used[u]) return 0;
    used[u]=1;
    int i,res;
    rep(i,0,N){
        if (graph[u][i]==1 && i!=v){
            res=dfs(i,u);
            if (!res)return 0;//closed graph
        }
    }
    return 1;
}

int main(){
    int i,u,v,ans=0;
    scanf("%d %d",&N,&M);
    rep(i,0,M){
        scanf("%d %d",&u,&v);
        u--;v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    rep(i,0,N) ans+=dfs(i,-1);
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&u,&v);
         ^