#include <stdio.h>

void rotate(int* x0, int* y0, int* x1, int* y1, int* x, int* y){
    *x = (*y1 - *y0) + *x0;
    *y = -1 * (*x1 - *x0) + *y0;
}

int main(void){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int x3, x4, y3, y4;
    rotate(&x2, &y2, &x1, &y1, &x3, &y3);
    rotate(&x3, &y3, &x2, &y2, &x4, &y4);
    printf("%d %d %d %d\n", x3, y3, x4, y4);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
     ^