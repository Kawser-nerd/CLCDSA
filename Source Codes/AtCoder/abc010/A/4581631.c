#include<stdio.h>

int main(void)
{
  char str[11];
  scanf("%s", str);
  printf("%spp\n",str);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str);
   ^