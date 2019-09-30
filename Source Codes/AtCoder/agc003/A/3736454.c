#include<stdio.h>
#include<string.h>
int main(void){
  int ns=0,we=0;
  char s[1001];
  scanf("%s",s);
  if(strchr(s,'N'))ns++;
  if(strchr(s,'S'))ns++;
  if(strchr(s,'W'))we++;
  if(strchr(s,'E'))we++;
  puts(ns%2+we%2?"No":"Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^