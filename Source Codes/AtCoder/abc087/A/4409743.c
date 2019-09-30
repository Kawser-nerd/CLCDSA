#include <stdio.h>

int main(){
  int x,a,b;
  scanf("%d\n%d\n%d",&x,&a,&b,stdin);
  x -= a;
  x -= (x/b)*b;
  printf("%d\n",x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: too many arguments for format [-Wformat-extra-args]
   scanf("%d\n%d\n%d",&x,&a,&b,stdin);
         ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n%d\n%d",&x,&a,&b,stdin);
   ^