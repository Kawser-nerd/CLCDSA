#include<stdio.h>

int main(void)
{
    int i, j, a[100], N, min = 200, max = -200, ans = 1000000, total = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        if(min > a[i])
            min = a[i];
        if(max < a[i])
            max = a[i];
    }

    for(i = min; i <= max; i++){
        total = 0;
        for(j=0;j<N;j++){
            total += (i - a[j]) * (i - a[j]);
        }
        if(ans > total)
            ans = total;
    }

    printf("%d", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^