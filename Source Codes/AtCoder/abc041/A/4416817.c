#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  char s[100];int i;
  scanf("%s %d",s,&i);
  printf("%c",s[i-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %d",s,&i);
   ^