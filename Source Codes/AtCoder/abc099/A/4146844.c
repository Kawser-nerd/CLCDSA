#include <stdio.h>

int main(void){
  char s[4] = "ABC";
  int n;
  scanf("%d", &n);
  if(n >= 1000) s[2] = 'D';
  printf("%s\n", s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^