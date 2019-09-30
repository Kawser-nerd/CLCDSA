#include <stdio.h>

int main() {
    int x;

    scanf("%d", &x);

    for (int i = 0; i <= x; i++) {
        if (x == i * i * i * i) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^