#include <stdio.h>
int main(void){
    int sx,sy,tx,ty;
    scanf("%d",&sx);
    scanf("%d",&sy);
    scanf("%d",&tx);
    scanf("%d",&ty);
    for(int i=sx;i<tx;i++)
        putchar('R');
    for(int i=sy;i<ty;i++)
        putchar('U');
    for(int i=tx;i>sx;i--)
        putchar('L');
    for(int i=ty;i>sy;i--)
        putchar('D');
    putchar('D');
    for(int i=sx;i<tx+1;i++)
        putchar('R');
    for(int i=sy-1;i<ty;i++)
        putchar('U');
    putchar('L');
    putchar('U');
    for(int i=tx;i>sx-1;i--)
        putchar('L');
    for(int i=ty+1;i>sy;i--)
        putchar('D');
    putchar('R');
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&sx);
     ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&sy);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&tx);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&ty);
     ^