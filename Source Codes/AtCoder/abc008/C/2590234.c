#include <stdio.h>

int main(void)
{
    int N, C[100], i, j, S;
    double ans = 0.0;

    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%d", &C[i]);
    }

    for(i=0; i<N; i++) {
        S = 0;
        for(j=0; j<N; j++) {
            if(i == j) {
                continue;
            }else if(C[i]%C[j] == 0) {
                S++;
            }
        }
        ans += S%2 ? 0.5 : (double)(S+2)/(2*S+2);
    }
    printf("%f\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &C[i]);
         ^