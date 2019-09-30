#include<stdio.h>

int main(void)
{
  int N=0;
  int i=0;
  double sum=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
       sum+=(i+1)*10000;
    }
  printf("%d\n",(int)(sum/N));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^