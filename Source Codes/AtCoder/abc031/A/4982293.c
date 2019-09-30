#include<stdio.h>
int main()
{
  int A,B;
  scanf("%d%d",&A,&B);
  if((A+1)*B>A*(B+1))
  {
    printf("%d\n",(A+1)*B);
  }
  if(A*(B+1)>(A+1)*B)
  {
    printf("%d\n",A*(B+1));
  }
  if((A+1)*B==A*(B+1))
  {
    printf("%d\n",(A+1)*B);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&A,&B);
   ^