#include <stdio.h>

int main(void) {
    int n;
    float ex;

    scanf("%d", &n);

    ex = (float)(1 + n) / 2;

    printf("%d\n", (int)(ex*10000));

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^