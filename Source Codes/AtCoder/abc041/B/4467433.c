#include<stdio.h>
int main(void)
{
  int a, b, c, x, ans;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d", (long long)a*b%1000000007*c%1000000007);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%d", (long long)a*b%1000000007*c%1000000007);
          ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^