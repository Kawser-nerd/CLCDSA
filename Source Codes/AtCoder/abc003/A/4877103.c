#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);

  double SUM = 0;
  for(int i = 1; i <= N; i++) {
    SUM += (i * 10000 * 1) / (double)N;
  }
  printf("%0.0f\n", SUM);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^