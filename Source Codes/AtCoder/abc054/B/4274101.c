#include <stdio.h>

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  char A[N][N],B[M][M];

  for(int i = 0;i < N;i++) scanf("%s",A[i]);
  for(int i = 0;i < M;i++) scanf("%s",B[i]);

  int flag = 1;
  for(int i = 0;i <= N-M;i++){
    for(int j = 0;j <= N-M;j++){
      flag = 1;
      for(int x = 0;x < M;x++){
        for(int y = 0;y < M;y++){
          if(A[i+x][j+y] != B[x][y]){
            flag = 0;
            break;
          }
        }
      }
      if(flag){
        printf("Yes\n");
        return 0;
      }
    }
  }

  printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:9:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%s",A[i]);
                            ^
./Main.c:10:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < M;i++) scanf("%s",B[i]);
                            ^