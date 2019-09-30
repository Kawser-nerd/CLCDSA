#include <stdio.h>
#define limit 10

int graph[limit][limit];
int flag[limit];

void init(int M){
  for(int i = 0;i < M;i++){
    for(int j = 0;j < M;j++){
      graph[i][j] = 0;
    }
  }
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int A,B;
  init(M);
  for(int i = 0;i < M;i++){
    scanf("%d%d",&A,&B);
    A--; B--;
    graph[A][B] = graph[B][A] = 1;
  }

  for(int i = 0;i < N;i++){
    int cnt = 0;
    for(int j = 0;j < N;j++) flag[j] = 0;
    flag[i] = 1;
    for(int j = 0;j < N;j++){
      if(graph[i][j] == 0) continue;
      for(int k = 0;k < N;k++){
        if(graph[j][k] && graph[i][k] == 0 && !flag[k]){
          cnt++;
          flag[k] = 1;
        }
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&A,&B);
     ^