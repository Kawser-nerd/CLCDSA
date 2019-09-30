#include <stdio.h>

int main() {
  int number_a, number_b;
  scanf("%d %d", &number_a, &number_b);
  printf("%d %d\n", number_b, number_a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &number_a, &number_b);
   ^