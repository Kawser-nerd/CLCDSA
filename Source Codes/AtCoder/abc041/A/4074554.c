#include <stdio.h>
int main(){
  char s[101];
  int i;
  scanf("%s %d", s, &i);
  printf("%c\n", s[i-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %d", s, &i);
   ^