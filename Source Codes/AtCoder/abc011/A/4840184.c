#include <stdio.h>

int main() {
  int month, next_month;
  scanf("%d", &month);
  next_month = (month == 12)? 1 : month + 1;
  printf("%d\n", next_month);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &month);
   ^