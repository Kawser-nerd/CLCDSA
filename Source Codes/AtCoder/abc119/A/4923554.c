#include<stdio.h>
#include<string.h>
        int main(void)
{
        char Y[11];
        scanf("%s", Y);
        if (strcmp(Y,"2019/04/30")<=0)
         printf("Heisei");
        else
         printf("TBD");
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", Y);
         ^