#include<stdio.h>
int main(void){
  char c;
  scanf("%c",&c);
  if('a'==c || 'i'==c || 'u'==c || 'e'==c || 'o'==c) printf("vowel\n");
  else printf("consonant\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&c);
   ^