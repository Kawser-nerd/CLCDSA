#include <stdio.h>
#include <string.h>

int main(void){
 char s[10];
 scanf("%s",s);

 if(s[0] == 'a' && strlen(s) == 1) printf("-1\n");
 else printf("a\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^