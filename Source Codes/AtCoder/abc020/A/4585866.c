#include<stdio.h>

int main(void)
{
  int i;
  scanf("%d",&i);
  if(i==1)
    {
      printf("ABC\n");
    }
  if(i==2)
    {
      printf("chokudai\n");
    }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&i);
   ^