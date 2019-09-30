#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int s[3], e[3];
    // ??
    for (size_t i = 0; i < 3; i++) {
        scanf("%d %d", &s[i], &e[i]);
    }
    // ??
    int sum = 0;
    for (size_t i = 0; i < 3; i++) {
        sum += s[i]*0.1*e[i];
    }
    // ??
    printf("%d\n", sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &s[i], &e[i]);
         ^