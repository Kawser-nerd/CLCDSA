#include<stdio.h>
int main(void){
  char s[101];
  long long k;
  int i = 0;
  scanf("%s",s);
  scanf("%lld",&k);
  while(--k != 0 && s[i] == '1') i++;
  putchar(s[i]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&k);
   ^