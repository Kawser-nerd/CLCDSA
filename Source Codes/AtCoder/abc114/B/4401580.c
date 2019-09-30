#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(void){
  char s[10];
  int i,min=9999;
  scanf("%s",s);
  for(i=0;i<strlen(s)-2;i++){
    int x=s[i]-'0',y=s[i+1]-'0',z=s[i+2]-'0';
    int sa=abs((100*x+10*y+z)-753);
    if(sa<min) min=sa;
  }
  printf("%d",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^