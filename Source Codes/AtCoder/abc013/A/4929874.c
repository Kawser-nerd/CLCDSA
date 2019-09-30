#include <stdio.h>

int main(void)
{
  int i;
  scanf("%c", &i);
  printf("%d\n", i-'A'+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
   scanf("%c", &i);
         ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c", &i);
   ^