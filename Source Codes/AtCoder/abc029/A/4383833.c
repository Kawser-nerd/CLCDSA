#include <stdio.h>
#include <string.h>

int main(void){
  char s[11];
  for(int i = 0;i < 11;i++) s[i] ='\0';
  scanf("%s",s);
  s[strlen(s)] = 's';
  printf("%s\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^