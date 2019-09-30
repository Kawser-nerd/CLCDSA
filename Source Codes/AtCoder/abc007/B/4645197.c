#include<stdio.h>

int main(void){
  char s[101];
  scanf("%s",s);
  if(s[0]=='a' && s[1]=='\0') printf("-1");
  else printf("a\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^