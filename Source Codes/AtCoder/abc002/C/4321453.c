#include <stdio.h>
#include <math.h>
int main(void){
    int x[3] = {0}; int y[3] = {0};
    for(int i = 0; i < 3; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    double S = 0.0;
    S = (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);
    if(S < 0){
        printf("%.1f\n", -1 * S / 2);
    }else {
        printf("%.1f\n", S / 2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &x[i], &y[i]);
         ^