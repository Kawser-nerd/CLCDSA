#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  int point[N+1][N+1];
  int dp[N+1][N+1];
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      scanf("%d",&point[i][j]);
    }
  }
  for(int i = 0;i < N+1;i++){
    for(int j = 0;j < N+1;j++){
      if(i == N || j == N) point[i][j] = 0;
    }
  }

  for(int i = 0;i < N+1;i++){
    for(int j = 0;j < N+1;j++){
      int res = 0;
      for(int x = i;x < N+1;x++){
        for(int y = j;y < N+1;y++){
          res += point[x][y];
        }
      }
      dp[i][j] = res;
    }
  }

  int MAX[N*N];
  for(int i = 0;i < N*N;i++){
    MAX[i] = -1;
  }
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      for(int x = i;x < N;x++){
        for(int y = j;y < N;y++){
          MAX[(x+1-i)*(y+1-j)-1] = max(MAX[(x+1-i)*(y+1-j)-1],dp[i][j]-dp[x+1][j]-dp[i][y+1]+dp[x+1][y+1]);
        }
      }
    }
  }

  for(int i = 1;i < N*N;i++){
    MAX[i] = max(MAX[i],MAX[i-1]);
  }

  int Q;
  scanf("%d",&Q);

  int p;
  for(int i = 0;i < Q;i++){
    scanf("%d",&p);
    printf("%d\n",MAX[p-1]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:18:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&point[i][j]);
       ^
./Main.c:58:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&Q);
   ^
./Main.c:62:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&p);
     ^