#include <stdio.h>

int main(void)
{
        int n;
        scanf("%d",&n);
        int i = 1,sum = 0;
        for(i;i <= n;i++)
                {
                        sum = sum + i;
                }
        printf("%d\n",sum);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n);
         ^