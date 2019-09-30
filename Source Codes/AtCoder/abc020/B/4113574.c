#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
  char s[8],t[8];
  int n;
  
  scanf("%s %s",s,t);
  strcat(s,t);
  
  n = atoi(s);
  
  printf("%d\n",n*2);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",s,t);
   ^