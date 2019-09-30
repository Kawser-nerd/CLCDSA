#include <stdio.h>

int main(void)
{
  int N, M, K_i, sum[30], A_j, result;
  int i, j;
  
  // ?????????
  scanf("%d %d", &N, &M);
  result = 0;
  for(i = 0; i < 30; i++)
  {
    sum[i] = 0;
  }
  
  // ???????????????????
  for(i = 0; i < N; i++)
  {
    scanf("%d", &K_i);
    for(j = 0; j < K_i; j++){
      scanf("%d", &A_j);
      sum[A_j - 1]++;
    }
  }
  
  // ????????????????????????
  for(i = 0; i < M; i++)
  {
    if(sum[i] == N) result++;
  }
  
  printf("%d", result);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &K_i);
     ^
./Main.c:21:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &A_j);
       ^