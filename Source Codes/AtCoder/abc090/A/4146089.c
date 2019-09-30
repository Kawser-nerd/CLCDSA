#include <stdio.h>

int main(void){
  char one[4];
  char two[4];
  char three[4];
  char ans[4] = {'\0'};
  scanf("%3s", one);
  scanf("%3s", two);
  scanf("%3s", three);
  ans[0] = one[0];
  ans[1] = two[1];
  ans[2] = three[2];
  printf("%s\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%3s", one);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%3s", two);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%3s", three);
   ^