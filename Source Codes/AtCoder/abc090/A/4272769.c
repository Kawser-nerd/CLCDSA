#include <stdio.h>
int main(){
  char a,b,c;
  scanf("%c%*c%*c %*c%c%*c %*c%*c%c", &a, &b, &c);
  printf("%c%c%c\n", a, b, c);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c%*c%*c %*c%c%*c %*c%*c%c", &a, &b, &c);
   ^