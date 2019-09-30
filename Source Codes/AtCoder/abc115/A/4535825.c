#include <stdio.h>

int main() {
  int D, i;
  scanf("%d", &D);
  printf("Christmas");
  for(i = 0; i < 25 - D; i++) {
    printf(" Eve");
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &D);
   ^