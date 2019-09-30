#include<stdio.h>

int main(void)
{
        int x[3],y[3],n,x1;

        scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);

        x1 = x[0];
        if(x[0]<x[1]){
                n =x[1] -x[0];
                y[2] = n+y[1];
                y[3] =n+y[0];
        }
        else{
                n =x[0]-x[1];
                y[2] = y[1]-n;
                y[3] = y[0]-n;
        }

        n = y[1] - y[0];
        x[2] = x[1] - n;
        x[3] = x1 - n;

        printf("%d %d %d %d\n",x[2],y[2],x[3],y[3]);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
         ^