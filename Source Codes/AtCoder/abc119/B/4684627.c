#include <stdio.h>

int main(void){
    int N;
    double ans = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        double x;
        scanf("%lf", &x);
        char str[3];
        scanf("%s", str);
        ans += str[0] == 'J' ? x : x * 380000;
    }
    printf("%lf", ans);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf", &x);
         ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", str);
         ^