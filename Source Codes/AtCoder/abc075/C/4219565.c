#include <stdio.h>
#define limit 50

int N,M;
int a[limit],b[limit];

int graph[limit][limit];
int flag[limit];

void dfs(int v){
  flag[v] = 1;
  for(int v2 = 0;v2 < N;v2++){
    if(graph[v][v2] == 0) continue;
    if(flag[v2] == 1) continue;
    dfs(v2);
  }
}

int main(void){
  int ans = 0;
  scanf("%d%d",&N,&M);

  for(int i = 0;i < limit;i++){
    for(int j = 0;j < limit;j++){
      graph[i][j] = 0;
    }
  }
  for(int i = 0;i < M;i++){
    scanf("%d%d",&a[i],&b[i]);
    a[i]--; b[i]--;
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;
  }

  for(int i = 0;i < M;i++){
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = 0;

    for(int j = 0;j < N;j++) flag[j] = 0;

    dfs(0);

    int bridge = 0;
    for(int j = 0;j < N;j++)
      if(flag[j] == 0)
        bridge = 1;
    if(bridge) ans++;

    graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a[i],&b[i]);
     ^