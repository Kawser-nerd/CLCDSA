#include <stdio.h>
int dists[300][300];
int main(void){
  int N;
  scanf("%d\n", &N);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      scanf("%d", &dists[i][j]);

  unsigned long long ans = 0;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j){
      int a = dists[i][j];
      int flg = 0;
      for(int k = 0; k < N; ++k){
        int b = dists[i][k] + dists[k][j];
        if (a > b) {
          puts("-1");
          return 0;
        } else if (a == b && i != j && j != k && k != i)
          flg = 1;
      }
      if (!flg)
        ans += a;
    }
  printf("%llu\n", ans/2);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n", &N);
   ^
./Main.c:8:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &dists[i][j]);
       ^