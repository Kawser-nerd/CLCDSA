#include <stdio.h>
int main(void){
  char s[4];
  int c = 1;
  scanf("%s", s);
  for(int i = 0; i < 3; i++){
      c *= s[i] - 'a' + 1;
  }
  printf("%s\n", (c == 6) ? "Yes" : "No");  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^