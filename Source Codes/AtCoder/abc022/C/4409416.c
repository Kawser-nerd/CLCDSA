#include <stdio.h>
#define INF 1 << 29

int N,M;
int graph[300][300];
long ans = INF;

long min(long a,long b){
  if(a < b){
    return a;
  }
  return b;
}

void init(){
  for(int i = 0;i < 300;i++){
    for(int j = 0;j < 300;j++){
      if(i != j) graph[i][j] = INF;
      else graph[i][j] = 0;
    }
  }
}

int main(void){
  scanf("%d%d",&N,&M);

  init();

  int u,v,l;
  for(int i = 0;i < M;i++){
    scanf("%d%d%d",&u,&v,&l);
    u--; v--;
    graph[u][v] = graph[v][u] = l;
  }

  for(int k = 1;k < N;k++){
    for(int i = 1;i < N;i++){
      for(int j = 1;j < N;j++){
        graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
      }
    }
  }

  for(int i = 1;i < N-1;i++){
    if(graph[0][i] == INF) continue;
    for(int j = i+1;j < N;j++){
      if(graph[0][j] == INF) continue;
      ans = min(ans,graph[0][i]+graph[i][j]+graph[j][0]);
    }
  }

  if(ans == INF) ans = -1;
  printf("%ld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&u,&v,&l);
     ^