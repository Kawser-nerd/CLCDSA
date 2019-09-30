#include <stdio.h>

int main(){
  int c,a,b;
  scanf("%d%d%d",&c,&a,&b);
  int area;
  area = a * c / 2;
  printf("%d\n",area);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&c,&a,&b);
   ^