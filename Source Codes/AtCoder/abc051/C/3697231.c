#include <stdio.h>
int main()
{
    int sx, sy, tx, ty, i, j, k;
    scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
    for (i = sy; i < ty; i++) { //first path
        putchar('U');
    }
    for (i = sx; i < tx; i++) {
        putchar('R');
    }
    for (i = ty; i > sy; i--) { //second path
        putchar('D');
    }
    for (i = tx; i > sx; i--) {
        putchar('L');
    }
    putchar('L');                //third path
    for (i = sy; i < ty + 1; i++) {
        putchar('U');
    }
    for (i = sx - 1; i < tx; i++) {
        putchar('R');
    }
    putchar('D');
    putchar('R');               //fourth path
    for (i = ty; i > sy - 1; i--) {
        putchar('D');
    }
    for (i = tx + 1; i > sx; i--) {
        putchar('L');
    }
    putchar('U');
    putchar('\n');
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
     ^