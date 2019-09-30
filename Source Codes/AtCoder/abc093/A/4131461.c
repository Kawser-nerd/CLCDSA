#include <stdio.h>

int main()
{
  char a, b, c;
  scanf("%c%c%c", &a, &b, &c);
  if (a != b && b != c && c != a)
    puts("Yes");
  else
    puts("No");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c%c%c", &a, &b, &c);
   ^