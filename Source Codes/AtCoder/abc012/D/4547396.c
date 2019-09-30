#include <stdio.h>
#define INF 1 << 29

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int graph[N][N];
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      if(i == j) graph[i][j] = 0;
      else graph[i][j] = INF;
    }
  }

  int a,b,t;
  for(int i = 0;i < M;i++){
    scanf("%d%d%d",&a,&b,&t);
    a--; b--;
    graph[a][b] = graph[b][a] = t;
  }

  for(int k = 0;k < N;k++){
    for(int i = 0;i < N;i++){
      for(int j = 0;j < N;j++){
        graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
      }
    }
  }

  int ans = INF;
  for(int i = 0;i < N;i++){
    int MAX = 0;
    for(int j = 0;j < N;j++){
      if(i == j) continue;
      MAX = max(MAX,graph[i][j]);
    }
    ans = min(MAX,ans);
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&t);
     ^