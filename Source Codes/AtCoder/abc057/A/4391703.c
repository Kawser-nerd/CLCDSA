#include<stdio.h>

int main(void)
{
        int a,b;

        scanf("%d%d",&a,&b);

        if(a+b<24)
                printf("%d\n",a+b);
        else
                printf("%d\n",a+b-24);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^