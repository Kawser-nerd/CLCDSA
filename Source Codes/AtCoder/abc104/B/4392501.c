#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(void){
  char s[110];
  scanf("%s",s);
  int i,j,k=strlen(s),csum=0;
  if(s[0]!='A'||s[1]<'a') {printf("WA");return 0;}
  for(i=2;i<k-1;i++){
    if(s[i]=='C') csum++;
    else if(s[i]<'a'||s[i]<='B'||s[i]<='D') {printf("WA");return 0;}
  }
  if(csum!=1) {printf("WA");return 0;}
  if(s[k-1]<'a'){printf("WA");return 0;}
  printf("AC");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^