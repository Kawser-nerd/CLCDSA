#include <stdio.h>

int main(void)
{
        int x,a,b;
        scanf("%d%d%d",&x,&a,&b);
        int la = (x-a)*(x-a);
        int lb = (x-b)*(x-b);
        if(la < lb)
                {printf("A\n");}
        else
                {printf("B\n");}
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&x,&a,&b);
         ^