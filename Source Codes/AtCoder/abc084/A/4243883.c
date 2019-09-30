#include <stdio.h>

int main(void)
{
        int m;
        scanf("%d",&m);
        int rest=48-m;
        printf("%d",rest);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&m);
         ^