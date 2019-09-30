#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  char s[50];
  scanf("%s",s);
  if(s[strlen(s)-1]=='T') printf("YES");
  else printf("NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^