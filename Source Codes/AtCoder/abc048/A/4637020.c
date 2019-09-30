#include<stdio.h>

int main(){
  char s[100];
  scanf("AtCoder %s Contest", s);
printf("A%cC", s[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("AtCoder %s Contest", s);
   ^