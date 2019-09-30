#include<stdio.h>
int main(void){
    int x[5], y[5];
    scanf("%d %d %d %d", &x[1], &y[1], &x[2], &y[2]);
    int t = x[2] - x[1];
    int s = y[2] - y[1];
    x[3] = x[2] - s;
    y[3] = y[2] + t;
    x[4] = x[1] - s;
    y[4] = y[1] + t;
    printf("%d %d %d %d\n",x[3], y[3], x[4], y[4]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &x[1], &y[1], &x[2], &y[2]);
     ^