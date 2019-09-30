#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(void) {
  char s1[1010];
  char s2[1010];
  scanf("%s",s1);
  memset(s2,s1[0],1);
  s2[1]='\0';
  for(int i=0; i<strlen(s1); i++) {
    if(s1[i]==s1[i+1]) {
      strncat(s2,&s1[i+1],1);
    }else{
      printf("%c%lu",s2[0],strlen(s2));
      memset(s2,s1[i+1],1);
      s2[1]='\0';
    }
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s1);
   ^