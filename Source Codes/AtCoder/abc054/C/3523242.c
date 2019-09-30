#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int g[9][9] = {};
int visit[9] = {}, N;

int dfs(int now){
  visit[now] = 1;
  
  int flag = 1, cnt = 0;
  int i;
  
  for(i = 1; i <= N; i++){
    flag *= visit[i];
  }
  if(flag){
    visit[now] = 0;
    return 1;
  }

  for(i = 2; i <= N; i++){
    if(g[now][i] == 1 && visit[i] == 0){
      cnt += dfs(i);
    }
  }
  visit[now] = 0;
  return cnt;
}
 
int main(void){

  int M;
  int i;

  scanf("%d%d", &N, &M);

  int a, b;

  for(i = 0; i < M; i++){
    scanf("%d%d", &a, &b);
    g[a][b] = 1;
    g[b][a] = 1;
  }

  printf("%d\n", dfs(1));
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &M);
   ^
./Main.c:43:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^