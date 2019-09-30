#include <stdio.h>

int main() {
  int X;
  scanf("%d",&X);
  if (X == 7 || X == 5 || X == 3) {
    printf("YES\n");
    return 0;
  }
  printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&X);
   ^