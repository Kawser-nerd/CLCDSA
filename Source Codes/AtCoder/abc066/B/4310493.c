#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  char s[201];
  scanf("%s",s);
  int i,n=strlen(s);
  for(i=n-2;i>0;i-=2){
    if(strncmp(s,s+i/2,i/2)==0){
      printf("%d",i);
      return 0;
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^