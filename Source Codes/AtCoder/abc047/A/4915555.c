#include <stdio.h>

int main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a + b == c || b + c == a || c + a == b) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^