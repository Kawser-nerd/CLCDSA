#include<stdio.h>
int main(void)
{
  char s[101];
  int n;
  scanf("%s", s);
  scanf("%d", &n);
  printf("%c\n", s[n-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^