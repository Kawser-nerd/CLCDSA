#include<ctype.h>
#include<stdio.h>
int main(void){
  char s[10],t[10],u[10];
  scanf("%s %s %s",s,t,u);
  printf("%c%c%c\n",toupper(s[0]),toupper(t[0]),toupper(u[0]));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s %s",s,t,u);
   ^