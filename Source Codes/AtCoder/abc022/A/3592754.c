#include <stdio.h>

int main() {
    int n, s, e;
    int w, a, cnt = 0;

    scanf("%d %d %d", &n, &s, &e);
    scanf("%d", &w);
    if (w >= s && w <= e) {
        cnt++;
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a);
        w += a;
        if (w >= s && w <= e) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &s, &e);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &w);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^