#include <stdio.h>
int main(void)
{
    int sx,sy,tx,ty;
    scanf("%d%d%d%d", &sx,&sy,&tx,&ty);
    int i;
    for(i=0; i<tx-sx; i++) printf("R");
    for(i=0; i<ty-sy; i++) printf("U");
    for(i=0; i<tx-sx; i++) printf("L");
    for(i=0; i<ty-sy; i++) printf("D");
    //1??
    printf("L");
    for(i=0; i<ty-sy+1; i++) printf("U");
    for(i=0; i<tx-sx+1; i++) printf("R");
    printf("D");
    printf("R");
    for(i=0; i<ty-sy+1; i++) printf("D");
    for(i=0; i<tx-sx+1; i++) printf("L");
    printf("U");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &sx,&sy,&tx,&ty);
     ^