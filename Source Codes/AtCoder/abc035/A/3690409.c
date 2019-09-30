#include <stdio.h>

int main() {
    int w, h;
    int n = 0;

    scanf("%d %d", &w, &h);

    n = w / 4;
    if (n * 3 == h) {
        printf("4:3\n");
    } else {
        printf("16:9\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &w, &h);
     ^