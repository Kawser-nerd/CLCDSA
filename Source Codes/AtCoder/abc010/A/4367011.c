#include <stdio.h>

int main(void){
  char s[10];
  scanf("%s",s);
  printf("%spp\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^