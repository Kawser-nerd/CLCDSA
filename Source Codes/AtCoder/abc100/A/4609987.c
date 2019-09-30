#include<stdio.h>

int main(void)
{
  int A, B;
  
  scanf("%d %d", &A, &B);
  
  if(A <= 8 && B <= 8)
    printf("Yay!");
  else
    printf(":(");
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &A, &B);
   ^