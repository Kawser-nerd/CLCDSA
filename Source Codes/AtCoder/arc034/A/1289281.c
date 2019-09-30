#include <stdio.h>
int main(void){
    int n, i;
    double MAX = 0.0;
    scanf("%d", &n);
    double a, b, c, d, e;
    for(i = 0; i < n; i++){
        scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
        double tmp = a + b + c + d + e * 110.0 / 900.0;
        if(MAX < tmp){
            MAX = tmp;
        }
    }
    printf("%.10lf\n", MAX);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
         ^