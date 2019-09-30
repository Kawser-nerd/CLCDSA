#include <stdio.h>
int main(){
  int a,ans=111;
  scanf("%d",&a);
  while(ans<a)ans+=111;
  printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^