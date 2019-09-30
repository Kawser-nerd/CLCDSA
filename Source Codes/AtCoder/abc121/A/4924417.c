#include <stdio.h>

int main()
{
    int H, W, h, w;
    
    scanf("%d%d",&H,&W);
    scanf("%d%d",&h,&w);
    
    printf("%d\n", H*W - h*W - w*(H-h));
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&H,&W);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^