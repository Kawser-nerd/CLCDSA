#include <stdio.h>
int main()
{
  int n,m;
  scanf("%1d %1d",&n,&m);
  if(n==9||m==9){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%1d %1d",&n,&m);
   ^