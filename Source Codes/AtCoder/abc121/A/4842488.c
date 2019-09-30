#include <stdio.h>

int main()
{
    int H, W, h, w;
    scanf("%d%d%d%d", &H, &W, &h, &w);

    printf("%d\n", (H - h) * (W - w));

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &H, &W, &h, &w);
     ^