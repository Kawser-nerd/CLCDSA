#include<stdio.h>
        int main(void)
{
        int A,B,S,N;
        scanf("%d%d", &A,&B);
        N = B % A;
         if(N == 0) S = A + B;
          else  S = B - A;
         printf("%d",S);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &A,&B);
         ^