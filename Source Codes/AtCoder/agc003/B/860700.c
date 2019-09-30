#include <stdio.h>

int n, data[100001], tmp;

int main(void)
{
    int i, j;
    long long int ans;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    tmp = 0;
    for (i = 0; i < n; i++) {
        if (data[i] != 0) {
            data[i] += tmp;
            ans += data[i] / 2;
            tmp = data[i] % 2;
        } else {
            tmp = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &data[i]);
         ^