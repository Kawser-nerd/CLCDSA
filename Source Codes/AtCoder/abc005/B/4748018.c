#include <stdio.h>

int main() {
  int i, N, min = 100, temp;
  scanf("%d", &N);
  for(i = 0; i < N; i++) {
    scanf("%d", &temp);
    min = (min > temp)? temp: min;
  }
  printf("%d\n", min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &temp);
     ^