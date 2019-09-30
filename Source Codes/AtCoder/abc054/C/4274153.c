#include <stdio.h>


int N,M;
int visited[9];
int graph[9][9]; 
int cnt = 0;
int end = 0;

void init(){
  for(int i = 0;i <= 8;i++){
    visited[i] = 0;
  }
}

void dfs(int v){
  int num = 0;
  for(int i = 1;i <= N;i++){
    if(visited[i]) num++;
  }
  if(num == N){
    cnt++;
    return;
  }

  for(int i = 1;i <= N;i++){
    if(visited[i]) continue;
    if(graph[v][i] == 0) continue;
    visited[i] = 1;
    dfs(i);
    visited[i] = 0;
  }
}

int main(void){
  scanf("%d%d",&N,&M);

  int a,b;
  for(int i = 0;i <= N;i++){
    for(int j = 0;j <= N;j++){
      graph[i][j] = 0;
    }
  }
  for(int i = 0;i < M;i++){
    scanf("%d%d",&a,&b);
    graph[a][b] = graph[b][a] = 1;
  }

  init();
  visited[1] = 1;
  dfs(1);

  printf("%d\n",cnt);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^