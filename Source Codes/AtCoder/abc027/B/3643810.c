#include <stdio.h>

int main() {
    int n;
    int a[101] = { 0 };
    int avg = 0, sum = 0, total = 0, num = 0, res = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum % n != 0) {
        printf("-1\n");
    } else {
        avg = sum / n;

        for (int i = 0; i < n; i++) {
            total += a[i];
            num += 1;
            if (total != avg * num) {
                res += 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^