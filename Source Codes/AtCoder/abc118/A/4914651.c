#include <stdio.h>

int main(){
  int a,b;
  scanf("%d %d\n",&a,&b);
  if(b % a == 0) printf("%d\n",a+b);
  else printf("%d\n",b-a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d\n",&a,&b);
   ^