#include <stdio.h>

int main(void) {
    int a, b, ans;

    scanf("%d %d", &a, &b);

    ans = (b - (a % b)) % b;

    printf("%d\n", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^