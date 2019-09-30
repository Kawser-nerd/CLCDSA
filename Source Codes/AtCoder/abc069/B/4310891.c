#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  char s[100];
  scanf("%s",s);
  int n=strlen(s)-2;
  printf("%c%d%c",s[0],n,s[n+1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^