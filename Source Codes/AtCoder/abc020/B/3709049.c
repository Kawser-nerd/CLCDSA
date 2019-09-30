#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(void) {
  char s1[100],s2[100];
  scanf("%s%s",s1,s2);
  strncat(s1,s2,3);
  printf("%ld\n",strtol(s1,NULL,10)*2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s",s1,s2);
   ^