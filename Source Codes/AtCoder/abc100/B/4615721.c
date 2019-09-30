#include<stdio.h>

int main(void)
{
  int D, N, sum, i, p = 1;
  
  scanf("%d %d", &D, &N);
  
  for(i = 0 ; i < D ; i++)
  {
    p = p * 100;
  }
  if(N < 100)
  {
    for(i = 0 ; i < N ; i++)
    {
      sum = sum + p;
    }
  }
  else
  {
    for(i = 0 ; i < N + 1 ; i++)
    {
      sum = sum + p;
    }
  }
  
  printf("%d", sum);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &D, &N);
   ^