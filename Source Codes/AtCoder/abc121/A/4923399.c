#include<stdio.h>

int main (void)
{
        int H, W, h, w, v, x, y, a;
        scanf("%d%d",&H, &W);
        scanf("%d%d",&h, &w);

        v=H*W;

        x=h*W+(H-h)*w;

        a=v-x;
        printf("%d\n",a);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&H, &W);
         ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&h, &w);
         ^