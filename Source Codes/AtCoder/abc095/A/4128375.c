#include <stdio.h>

int main()
{
  int b = 700;
  char a;
  for (int i = 3; i; i--)
  {
    scanf("%c", &a);
    if (a == 'o')
      b += 100;
  }
  printf("%d\n", b);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &a);
     ^