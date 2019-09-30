#include <stdio.h>
#include <string.h>
int main(void){
  char s[100000];
  int i;
  scanf("%s",s);
  for(i=0;i<strlen(s);i+=2){
    printf("%c",s[i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^