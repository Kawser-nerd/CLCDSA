#include <stdio.h>
int main(void){
  char s[100];
  int i;
  scanf("%s",s);
  scanf("%d",&i);
  printf("%c",s[i-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&i);
   ^