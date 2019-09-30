#include <stdio.h>

int gcd(int a, int b) {
  int tmp;
  if(a < b) { tmp = a; a = b; b = tmp; }
  while(b != 0)
  {
    a %= b;
    tmp = a; a = b; b = tmp;
  }
  return a;
}

int main()
{
  int n; scanf("%d", &n);
  printf("%d\n", n*2/gcd(n, 2));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:10: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   int n; scanf("%d", &n);
          ^