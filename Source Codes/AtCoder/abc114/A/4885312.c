#include<stdio.h>

int main()
{
  int X;
  scanf("%d",&X);
  if(X==3||X==5||X==7){
    printf("YES");
  }else{
    printf("NO");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&X);
   ^