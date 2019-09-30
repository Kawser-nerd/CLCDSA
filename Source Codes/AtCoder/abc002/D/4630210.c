#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int x,y;
  int graph[N][N];
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      graph[i][j] = 0;
    }
  }
  for(int i = 0;i < M;i++){
    scanf("%d%d",&x,&y);
    x--; y--;
    graph[x][y] = graph[y][x] = 1;
  }

  int ans = 0;
  int flag[N];
  for(int i = 1;i < 1<<N;i++){
    int res = 0;
    for(int j = 0;j < N;j++){
      if((i >> j)&1){
        flag[j] = 1;
        res++;
      }else flag[j] = 0;
    }
    int habatudenai = 0;
    for(int v = 0;v < N;v++){
      if(flag[v] == 0) continue;
      for(int v2 = 0;v2 < N;v2++){
        if(v == v2) continue;
        if(flag[v2] == 0) continue;
        if(graph[v][v2] == 0){
          habatudenai = 1;
          break;
        }
      }
    }
    if(habatudenai == 0){
      ans = max(res,ans);
    }
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^