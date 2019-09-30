#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    int l1, l2, l3;
    // ??
    scanf("%d %d %d", &l1, &l2, &l3);
    // ??
    if (l1 == l2) {
        printf("%d\n", l3);
    } else if (l1 == l3) {
        printf("%d\n", l2);
    } else if (l2 == l3) {
        printf("%d\n", l1);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &l1, &l2, &l3);
     ^