#include <stdio.h>

int main(void)
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%s\n", (b-a == c-b)? "YES" : "NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^