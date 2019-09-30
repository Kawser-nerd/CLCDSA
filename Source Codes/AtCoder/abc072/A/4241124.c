#include <stdio.h>

int main(void)
{
        int X,t;
        scanf("%d%d",&X,&t);
        if(X >= t)
                {
                int r=X-t;
                printf("%d",r);
                }
        else
                {
                printf("0");
                }
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&X,&t);
         ^