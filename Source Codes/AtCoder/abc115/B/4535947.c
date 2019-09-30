#include <stdio.h>

int main() {
  int N, i, max = 0, total = 0;
  scanf("%d", &N);
  int price[10];
  for(i = 0; i < N; i++) {
    scanf("%d", &price[i]);
    total += price[i];
    if(max < price[i]) {
      max = price[i];
    }
  }
  printf("%d\n", total - max / 2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &price[i]);
     ^