#include <stdio.h>

int main() {
    int n, a, cnt = 0;
    float sum = 0.0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a != 0) {
            sum += a;
            cnt++;
        }
    }

    printf("%d\n", (int)((sum / cnt) + 0.9));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^