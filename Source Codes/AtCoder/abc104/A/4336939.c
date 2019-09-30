#include <stdio.h>

int main(void)
{
        int r;

        scanf("%d",&r);

        if(r<1200)      printf("ABC\n");
        else if(r<2800) printf("ARC\n");
        else            printf("AGC\n");

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&r);
         ^