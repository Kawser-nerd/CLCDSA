#include<stdio.h>
int main()
{
  int N;
  scanf("%d",&N);
  if(N%1111==0)
  {
    printf("SAME\n");
  }
  else if(N%1111!=0)
  {
    printf("DIFFERENT\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^