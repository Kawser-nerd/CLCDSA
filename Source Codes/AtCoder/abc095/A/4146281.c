#include <stdio.h>

int main(void){
  char s[4] = {'\0'};
  scanf("%3s", s);
  int num = 700;
  for(int i = 0; i < 3; i++){
    if(s[i] == 'o') num += 100;
  }
  printf("%d\n", num);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%3s", s);
   ^