#include <stdio.h>
int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  if(a%2==0||b%2==0)printf("No");
  else printf("Yes");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^