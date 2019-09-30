#include <stdio.h>
#include <string.h>
int main(){
  char c[2];

  scanf("%c", c);

  if(c[0] == 'a' || c[0] == 'i' || c[0] == 'u' || c[0] == 'e' || c[0] == 'o'){
    printf("vowel\n");
  }else{
    printf("consonant\n");
  }

} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c", c);
   ^