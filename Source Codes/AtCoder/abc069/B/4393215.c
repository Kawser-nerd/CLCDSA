#include<stdio.h>
#include<string.h>

int main(void){
  int i,l;
  char s[100];
  scanf("%s",s);
  l=strlen(s);
  printf("%c%d%c\n",s[0],l-2,s[l-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^