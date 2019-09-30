#include <stdio.h>

int main(){
  int n,a;
  scanf("%d\n%d",&n,&a);
  if(n % 500 <= a) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n%d",&n,&a);
   ^