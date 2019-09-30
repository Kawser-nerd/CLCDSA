#include <stdio.h>
int main(void)
{
  int A,B,C,result;
  scanf("%d %d %d",&A,&B,&C);
  if ((A+B+1)>=C) result=B+C;
  else result=2*B+A+1;
  printf("%d",result);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&C);
   ^