#include <stdio.h>

int main(void)
{
        int N,K,X,Y,sum;
        scanf("%d%d%d%d",&N,&K,&X,&Y);
                if(N <= K)
                        {sum = N*X;}
                else
                        {sum = K*X + (N-K)*Y;}
        printf("%d\n",sum);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d%d",&N,&K,&X,&Y);
         ^