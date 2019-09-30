#include <stdio.h>

int main(void){
  int n;
  scanf("%d" ,&n);
  char s[4] = {'\0'};
  char ans[7];
  sprintf(s, "%d", n);
  ans[0] = 'A';
  ans[1] = 'B';
  ans[2] = 'C';
  ans[3] = s[0];
  ans[4] = s[1];
  ans[5] = s[2];
  ans[6] = '\0';
  printf("%s\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d" ,&n);
   ^