#include <stdio.h>
#define INF 1 << 29
#define limit 10

int graph[limit][limit];
int flag[limit];

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

void init(int N){
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      if(i != j) graph[i][j] = INF;
      else graph[i][j] = 0;
    }
  }
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int A,B;
  init(N);
  for(int i = 0;i < M;i++){
    scanf("%d%d",&A,&B);
    A--; B--;
    graph[A][B] = graph[B][A] = 1;
  }

  for(int k = 0;k < N;k++){
    for(int i = 0;i < N;i++){
      for(int j = 0;j < N;j++){
        graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
      }
    }
  }

  for(int i = 0;i < N;i++){
    int cnt = 0;
    for(int j = 0;j < N;j++){
      if(graph[i][j] == 2) cnt++;
    }
    printf("%d\n",cnt);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&A,&B);
     ^