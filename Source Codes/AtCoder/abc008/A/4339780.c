#include<stdio.h>

int main(void)
{
  int S,T;
   scanf("%d%d",&S,&T);
        printf("%d\n",T-S+1);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d",&S,&T);
    ^