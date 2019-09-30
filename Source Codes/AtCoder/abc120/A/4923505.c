#include<stdio.h>

int main (void)
{
int A,B,C,o;

        scanf("%d%d%d",&A,&B,&C);

        o = B/A;

        if(o>C) printf("%d\n",C);
        else    printf("%d\n",o);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&A,&B,&C);
         ^