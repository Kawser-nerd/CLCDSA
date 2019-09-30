#include <stdio.h>

int main(void){
  char s[5];
  int N;
  scanf("%s%d",s,&N);

  printf("%c%c\n",s[((N-1)/5)%5],s[(N-1)%5]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%d",s,&N);
   ^