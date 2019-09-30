#include <stdio.h>

int main() {
    int n, a, b;
    int color[1000001] = { 0 };
    int max = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        color[a]++;
        color[b+1]--;
    }

    for (int i = 1; i <= 1000000; i++) {
        color[i] += color[i-1];
    }

    for (int i = 0; i <= 1000000; i++) {
        if (max < color[i]) {
            max = color[i];
        }
    }

    printf("%d\n", max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a, &b);
         ^