#include<stdio.h>
int main()
{
  int x,y,z;
  scanf("%d %d",&x,&y);
  z = y / x;
  printf("%d\n",z);
  return 0;
} ./Main.c: In function �main�:
./Main.c:5:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&x,&y);
   ^