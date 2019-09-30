#include <stdio.h>
int main(void){
    // Here your code !
    int n;
    int i;
    int a,b,c,d,e;
    double ans=0;
    double temp;
    scanf("%d", &n);

    for( i = 0; i < n; ++i){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        temp = a + b + c + d +(double) e*(11/(double)90);
        if( ans < temp){
            ans = (double)temp;
        }
    }
    printf("%f\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
         ^