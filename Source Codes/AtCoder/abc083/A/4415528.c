#include <stdio.h>

int main(){
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d,stdin);
  if(a + b > c + d) printf("Left\n");
  else if(a + b == c + d) printf("Balanced\n");
  else printf("Right\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: too many arguments for format [-Wformat-extra-args]
   scanf("%d %d %d %d",&a,&b,&c,&d,stdin);
         ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a,&b,&c,&d,stdin);
   ^