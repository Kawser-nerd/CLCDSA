#include <stdio.h>

int main() {
  int month, day;
  scanf("%d", &month);
  scanf("%d", &day);
  (month % day == 0)? printf("YES\n") : printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &month);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &day);
   ^