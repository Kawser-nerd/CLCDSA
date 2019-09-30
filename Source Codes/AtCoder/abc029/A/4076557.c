#include <stdio.h>
int main()
{
  char W[11];
  scanf("%s", W);
  printf("%ss\n", W);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", W);
   ^