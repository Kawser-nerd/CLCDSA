#include <stdio.h>

int main() {
  int ch;
  scanf("%c", &ch);
  ch = ch - 'A' + 1;
  printf("%d\n", ch);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
   scanf("%c", &ch);
         ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c", &ch);
   ^