#include <stdio.h>
#define mod 1000000007
#define INF 1 << 29

int main(void){
  int N,a,b,M;
  scanf("%d%d%d%d",&N,&a,&b,&M);
  a--; b--;

  int graph[N][N];
  int dist[N][N];
  long long dp[N][N];
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      if(i != j) graph[i][j] = INF;
      else graph[i][j] = 0;
      dp[i][j] = 0;
      dist[i][j] = INF;
    }
  }
  int x,y;
  for(int i = 0;i < M;i++){
    scanf("%d%d",&x,&y);
    x--; y--;
    graph[x][y] = graph[y][x] = 1;
  }

  dp[0][a] = 1;
  dist[0][a] = 0;
  int k;
  for(k = 0;dist[k][b] >= INF;k++){
    for(int i = 0;i < N;i++){
      if(dist[k][i] != k) continue;
      for(int j = 0;j < N;j++){
        if(graph[i][j] >= INF) continue;
        if(dist[k+1][j] >= INF){
          dist[k+1][j] = k+1;
          dp[k+1][j] = dp[k][i];
        }else{
          dp[k+1][j] += dp[k][i];
          dp[k+1][j]%mod;
        }
      }
    }
  }

  printf("%lld\n",dp[k][b]%mod);
   

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&N,&a,&b,&M);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^