#include <stdio.h>
int min(int a, int b){
  return (a<b) ? a : b;
}
int main(void){
  int a, b, c, d;
  scanf("%d%d%d%d", &a,&b, &c, &d);
  printf("%d\n", min(a, b) + min(c, d));  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &a,&b, &c, &d);
   ^